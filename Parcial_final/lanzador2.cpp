#include "lanzador2.h"
#include <QDebug>




lanzador2::lanzador2(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    setScene(scene);
    view = new QGraphicsView(this);
    view->setScene(scene);
    view->scale(1,-1);


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);
    setWindowTitle("Batalla");



    ofensivo = new canon_o();
    scene->addItem(ofensivo);

    defensivo = new canon_d();
    scene->addItem(defensivo);

    /*BalaO = new balaO();
    BalaO->setPosx(500);
    BalaO->setPosy(300);
    BalaO->setPos(500,300);*/

    //scene->addItem(BalaO);
    time = new QTimer;
    time->start(200);
    connect(time,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
    connect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
    show();
}



void lanzador2::Actualizacion1()
{
    ofensivo->setPosx(this->getXcanonOfensivo());
    ofensivo->setPosy(this->getYcanonOfensivo());
    ofensivo->setPos(this->getXcanonOfensivo(),this->getYcanonOfensivo());

    defensivo->setPosx(this->getXcanonDefensivo());
    defensivo->setPosy(this->getYcanonDefensivo());
    defensivo->setPos(this->getXcanonDefensivo(),this->getYcanonDefensivo());
    //qDebug()<<"Datos ingresados en launcher";
    //disconnect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

void lanzador2::Lanzamiento1()
{
    int flag = 0;
        float x,y, pi = 3.1416, g = 9.8, auxX,auxY;
        float Vxo,Vy0;
        int V0o = 0;
        int t = 0;
        int angle = 0;
        float aux =this->getXcanonOfensivo()-this->getXcanonDefensivo();

        for(V0o = 5; ; V0o += 5){
            for(angle = 0; angle < 90; angle++){
                Vxo = V0o*cos(angle*pi/180);

                x = 0.0;
                y = 0.0;

                for(t = 0; ; t++){
                     Vy0 = (V0o*sin(angle*pi/180))-g*t;
                    x = this->getYcanonDefensivo()+Vxo*t;
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


                        flag += 1;
                        V0o += 50;
                         //qDebug()<<"entra a eso";

                        //disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
                        break;
                    }
                    if(y < 0){
                        break;
                    }
                }
                if(flag == 3) break;

               // disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
            }
            if(flag == 3) break;
            //disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
        }
        if(flag != 3){
            //cout << "No impacto en los disparos esperados"<< endl;
             qDebug()<<"no impacta";
            disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
        }
        qDebug()<<"bala disparada 3 veces";
        for(int i=0; i<=2;i++){
            if(i==0){
                grafica(tiempo.at(i),vooo1.at(i),angleoo1.at(i));
                this->setAngle(angleoo1.at(i));
                this->setT(tiempo.at(i));
                this->setV0o(vooo1.at(i));
            }
            else if(i==1){
                grafica2(tiempo.at(i),vooo1.at(i),angleoo1.at(i));
            }
            else if(i==2){
                grafica3(tiempo.at(i),vooo1.at(i),angleoo1.at(i));
            }
        }
        prueba1 = new balaO();
        scene->addItem(prueba1);
        connect(time,SIGNAL(timeout()), this,SLOT(grafica_fluida()));
        disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
}

void lanzador2::grafica_fluida()
{
     float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    //float aux2=0;

        //aux = this->getT()/10;

        aux2 += this->getT()/100;
        vyo= this->getV0o()*sin(this->getAngle()*pi/180)-g*aux;
        auxX = (this->getXcanonOfensivo()+(this->getV0o()*aux2)+40);
        auxY = this->getYcanonOfensivo()+vyo*aux-(0.5*g*(aux*aux)+40);

        prueba1->setPosx(auxX);
        prueba1->setPosy(auxY);
        prueba1->setPos(auxX,auxY);

        //qDebug()<<"Graficandoo";
   if(aux2 == this->getT()){
       delete prueba1;
        disconnect(time,SIGNAL(timeout()), this,SLOT(grafica_fluida()));
        qDebug()<<"Desconectoooo!";
    }
}

void lanzador2::grafica(int t, int V0o,int angle)
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

void lanzador2::grafica2(int t, int V0o, int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;



            num=t/10.0;

         for (int i = 0 ; i <balaOf2.size(); i++) {
                aux += num;

             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonOfensivo()+(V0o*cos(angle*pi/180)*aux))+40;


             auxY = this->getYcanonOfensivo()+vyo*aux-(0.5*g*(aux*aux))+40;

             //balaOf.at(i)->scale();
             balaOf2.at(i)->setPosx(auxX);
             balaOf2.at(i)->setPosy(auxY);
             balaOf2.at(i)->setPos(auxX,auxY);
             scene->addItem(balaOf2.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}

void lanzador2::grafica3(int t, int V0o, int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;



            num=t/10.0;

         for (int i = 0 ; i <balaOf3.size(); i++) {
                aux += num;

             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonOfensivo()+(V0o*cos(angle*pi/180)*aux))+40;


             auxY = this->getYcanonOfensivo()+vyo*aux-(0.5*g*(aux*aux))+40;

             //balaOf.at(i)->scale();
             balaOf3.at(i)->setPosx(auxX);
             balaOf3.at(i)->setPosy(auxY);
             balaOf3.at(i)->setPos(auxX,auxY);





             scene->addItem(balaOf3.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}

QList<balaO *> lanzador2::diez_bolas()
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


int lanzador2::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void lanzador2::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int lanzador2::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void lanzador2::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int lanzador2::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void lanzador2::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int lanzador2::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void lanzador2::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}



int lanzador2::getAngle() const
{
    return angle;
}

void lanzador2::setAngle(int value)
{
    angle = value;
}

int lanzador2::getV0o() const
{
    return V0o;
}

void lanzador2::setV0o(int value)
{
    V0o = value;
}

int lanzador2::getT() const
{
    return t;
}

void lanzador2::setT(int value)
{
    t = value;
}
