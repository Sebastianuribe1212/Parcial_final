//se lanza cuando presionamos el trecer boton del menu
#include "lanzador3.h"
#include <QDebug>


lanzador3::lanzador3(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    setScene(scene);
    view = new QGraphicsView(this);
    view->setScene(scene);
    view->scale(1,-1);//esto es para graficar en la escena como si fuera un plano cartesiano


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);
    setWindowTitle("Batalla");



    ofensivo = new canon_o();
    scene->addItem(ofensivo);

    defensivo = new canon_d();
    scene->addItem(defensivo);
    time = new QTimer;
    time->start(200);
    connect(time,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
    connect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
    show();
}



void lanzador3::Actualizacion1()
{
    ofensivo->setPosx(this->getXcanonOfensivo());
    ofensivo->setPosy(this->getYcanonOfensivo());
    ofensivo->setPos(this->getXcanonOfensivo(),this->getYcanonOfensivo());

    defensivo->setPosx(this->getXcanonDefensivo());
    defensivo->setPosy(this->getYcanonDefensivo());
    defensivo->setPos(this->getXcanonDefensivo(),this->getYcanonDefensivo());

}

void lanzador3::Lanzamiento1()
{
    int flag = 0;
        float x,y, pi = 3.1416, g = 9.8;
        float Vxo,Vy0;
        int V0o = 0;
        int t = 0;
        int angle = 0;


        for(V0o = 5; ; V0o += 5){
            for(angle = 0; angle < 90; angle++){
                Vxo = V0o*cos(angle*pi/180);

                x = 0.0;
                y = 0.0;

                for(t = 0; ; t++){
                     Vy0 = (V0o*sin(angle*pi/180))-g*t;
                    x = this->getYcanonOfensivo()+Vxo*t;
                    y = (this->getYcanonOfensivo() + Vy0*t) -(g*(t*t)/2);

                    if(sqrt(pow((this->getXcanonDefensivo() - x),2)+pow((this->getYcanonDefensivo()- y),2)) < 0.050*(this->getXcanonDefensivo())){
                        if(y<0) y = 0;

                        balaO *prueba = new balaO();
                        prueba->setPosx(x);
                        prueba->setPosy(y);
                        prueba->setPos(x,y);
                        scene->addItem(prueba);
                            vooo1.push_back(V0o);
                            angleoo1.push_back(angle);
                            tiempo.push_back(t);
                        qDebug()<<"tiempo: "<<t<<" angulo: "<<angle<<" vxo: "<<Vxo<<" V0o: "<<V0o;


                        flag += 3;
                        V0o += 50;

                        break;
                    }
                    if(y < 0){
                        break;
                    }
                }
                if(flag == 3) break;


            }
            if(flag == 3) break;

        }
        if(flag != 3){

             qDebug()<<"no impacta";
            disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
        }
        qDebug()<<"bala disparada 3 veces";
        for(int i=0; i<=2;i++){
            if(i==0){
                grafica(tiempo.at(i),vooo1.at(i),angleoo1.at(i));
                grafica2(tiempo.at(i),vooo1.at(i),angleoo1.at(i));
                this->setAngle(angleoo1.at(i));
                this->setT(tiempo.at(i));
                this->setV0o(vooo1.at(i));
            }

        }
        prueba1 = new balaO();
        scene->addItem(prueba1);
        //connect(time,SIGNAL(timeout()), this,SLOT(grafica_fluida()));
        disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
}


//grafica de balas ofensivas
void lanzador3::grafica(int t, int V0o,int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;

            num=t/10.0;

         for (int i = 0 ; i <balaOf.size(); i++) {
                aux += num;

             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonOfensivo()+(V0o*cos(angle*pi/180)*aux))+40;
             auxY = this->getYcanonOfensivo()+vyo*aux-(0.5*g*(aux*aux))+40;
             balaOf.at(i)->setPosx(auxX);
             balaOf.at(i)->setPosy(auxY);
             balaOf.at(i)->setPos(auxX,auxY);
             scene->addItem(balaOf.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}
//grafica de balas defensivas
void lanzador3::grafica2(int t, int V0o, int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;

            num=t/10.0;

         for (int i = 0 ; i <balaOf.size(); i++) {
                aux += num;

             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonDefensivo()+(V0o*-cos(angle*pi/180)*aux))-40;
             auxY = this->getYcanonDefensivo()+vyo*aux-(0.5*g*(aux*aux))+40;
             balaDef.at(i)->setPosx(auxX);
             balaDef.at(i)->setPosy(auxY);
             balaDef.at(i)->setPos(auxX,auxY);
             scene->addItem(balaDef.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}


//lista de balas ofensivas
QList<balaO *> lanzador3::diez_bolas()
{
    QList<balaO*>bala;
    balaO * bala1 = new balaO();
    bala.push_back(bala1);
    balaO * bala2 = new balaO();
    bala.push_back(bala2);
    balaO * bala3 = new balaO();
    bala.push_back(bala3);
    balaO * bala4 = new balaO();
    bala.push_back(bala4);
    balaO * bala5 = new balaO();
    bala.push_back(bala5);
    balaO * bala6 = new balaO();
    bala.push_back(bala6);
    balaO * bala7 = new balaO();
    bala.push_back(bala7);
    balaO * bala8 = new balaO();
    bala.push_back(bala8);
    balaO * bala9 = new balaO();
    bala.push_back(bala9);
    balaO * bala10 = new balaO();
    bala.push_back(bala10);

    return bala;
}
//lista de balas defensivas
QList<balad *> lanzador3::diez_bolasDef()
{
    QList<balad*>bala;
    balad * bala1 = new balad();
    bala.push_back(bala1);
    balad * bala2 = new balad();
    bala.push_back(bala2);
    balad * bala3 = new balad();
    bala.push_back(bala3);
    balad * bala4 = new balad();
    bala.push_back(bala4);
    balad * bala5 = new balad();
    bala.push_back(bala5);
    balad * bala6 = new balad();
    bala.push_back(bala6);
    balad * bala7 = new balad();
    bala.push_back(bala7);
    balad * bala8 = new balad();
    bala.push_back(bala8);
    balad * bala9 = new balad();
    bala.push_back(bala9);
    balad * bala10 = new balad();
    bala.push_back(bala10);

    return bala;
}


int lanzador3::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void lanzador3::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int lanzador3::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void lanzador3::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int lanzador3::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void lanzador3::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int lanzador3::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void lanzador3::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}

int lanzador3::getAngle() const
{
    return angle;
}

void lanzador3::setAngle(int value)
{
    angle = value;
}

int lanzador3::getV0o() const
{
    return V0o;
}

void lanzador3::setV0o(int value)
{
    V0o = value;
}

int lanzador3::getT() const
{
    return t;
}

void lanzador3::setT(int value)
{
    t = value;
}
