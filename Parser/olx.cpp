#include "Olx.h"

Olx::Olx(OlxQueryBuilder QBuilder) : queryBuilder(QBuilder)
{
    request = new Requesting;
}

Olx::~Olx()
{
    delete request;
}



QList<QUrl> Olx::listingsList(const QByteArray arr)
{
    QList<QUrl> listings;
    QGumboDocument document = QGumboDocument::parse(arr);
    QGumboNode root = document.rootNode();
    QGumboNodes aNodes = root.getElementsByClassName("detailsLink");
    for(auto a : aNodes)
        listings.append(a.getAttribute("href"));
    return listings;
}

QList<Listing*> Olx::readListingsList()
{
    static int page = 1;
    auto response = request->pageText(queryBuilder.toUrl(page/*++*/));
    QList<QUrl> addresses = listingsList(response);
    QList<Listing*> listings;
    for(auto x : addresses)
        listings.append(new OlxListing(x));
    return listings;
}

