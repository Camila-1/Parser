#include "Controller.h"



Controller::Controller(QObject *parent) : QObject(parent)
{
    doc = new Document;
    engine.rootContext()->setContextProperty("controller", this);
    QQmlComponent component(&engine, QUrl("qrc:/qml/QML/main.qml"));
    QString test =  component.errorString();
    root = component.create();
    DataBase db = DataBase::instance();
}

Controller::~Controller()
{
    delete root;
}

void Controller::start()
{
//    OlxQueryBuilder builder("kvartiry", "prodazha");
//    Site* site = new Olx(builder);
    DataBase db = DataBase::instance();
    UyBorQueryBuilder builder("kvartiry-v-tashkente", "prodazha-kvartir");
    //Site* site = new UyBor(builder);
    std::shared_ptr<Site> site(new UyBor(builder));
    Parser parser(db, site);
    parser.parse();
}
