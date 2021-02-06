//se lanza al presionar el segundo boton
#include "lanzador2.h"
#include <QDebug>




lanzador2::lanzador2(QWidget * parent)
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


//la funcion actualizacion le da la posicion a los cañones
void lanzador2::Actualizacion1()
{
    ofensivo->setPosx(this->getXcanonOfensivo());
    ofensivo->setPosy(this->getYcanonOfensivo());
    ofensivo->setPos(this->getXcanonOfensivo(),this->getYcanonOfensivo());

    defensivo->setPosx(this->getXcanonDefensivo());
    defensivo->setPosy(this->getYcanonDefensivo());
    defensivo->setPos(this->getXcanonDefensivo(),this->getYcanonDefensivo());

}
/*La funcion lanzamiento encuentra los datos en los que la bala impacta, al encontrar uno, guarda sus
datos en listas para ser usados màs tarde para graficarlos
*/
void lanzador2::Lanzamiento1()
{
    int flag = 0;
        float x,y, pi = 3.1416, g = 9.8;
        float Vxo,Vy0;
        int V0o = 0;
        int t = 0;
        int angle = 0;

        for(V0o = 5; ; V0o += 5){
            for(angle =0; angle <90; angle++){
                Vxo = V0o*cos(angle*pi/180);

                x = 0.0;
                y = 0.0;

                for(t = 0; ; t++){
                     Vy0 = (V0o*sin(angle*pi/180))-g*t;
                    x = this->getYcanonDefensivo()+Vxo*t*1;
                    y = (this->getYcanonDefensivo() + Vy0*t) -(g*(t*t)/2);

                    if(sqrt(pow((this->getXcanonDefensivo() - x),2)+pow((this->getYcanonDefensivo()- y),2)) < 0.025*(this->getXcanonDefensivo())){
                        if(y<0) y = 0;
                            vooo1.push_back(V0o);
                            angleoo1.push_back(angle);
                            tiempo.push_back(t);
                        qDebug()<<"tiempo: "<<t<<" angulo: "<<angle<<" vxo: "<<Vxo<<" V0o: "<<V0o;
                        flag += 1;
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
                this->setAngle(angleoo1.at(i));
                this->setT(tiempo.at(i));
                this->setV0o(vooo1.at(i));
            }
            else if(i==1){
                grafica2(tiempo.at(i),vooo1.at(i),angleoo1.at(i));//graficamos la primera linea de balas defensivas
            }
            else if(i==2){
                grafica3(tiempo.at(i),vooo1.at(i),angleoo1.at(i));//graficamos la segunda  linea de balas esta es la defensivas
            }
        }
        prueba1 = new balad();
        scene->addItem(prueba1);
        //connect(time,SIGNAL(timeout()), this,SLOT(grafica_fluida()));
        disconnect(time,SIGNAL(timeout()), this,SLOT(Lanzamiento1()));
}

void lanzador2::grafica_fluida()
{
     float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
        aux2 += this->getT()/100;
        vyo= this->getV0o()*sin(this->getAngle()*pi/180)-g*aux;
        auxX = (this->getXcanonOfensivo()+(this->getV0o()*aux2)-40);
        auxY = this->getYcanonOfensivo()+vyo*aux-(0.5*g*(aux*aux)-40);

        prueba1->setPosx(auxX);
        prueba1->setPosy(auxY);
        prueba1->setPos(auxX,auxY);

   if(aux2 == this->getT()){
       delete prueba1;
        disconnect(time,SIGNAL(timeout()), this,SLOT(grafica_fluida()));
        qDebug()<<"Desconectoooo!";
    }
}
//ingresan los datos para poner en la escena la secuencia de balas
void lanzador2::grafica(int t, int V0o,int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;
       num=t/10.0;

         for (int i = 0 ; i <balaOf.size(); i++) {
                aux += num;
             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonDefensivo()+(V0o*-cos(angle*pi/180)*aux))-40;//le damos el angulo negativo para hacer el disparo hacia el otro lado
             auxY = this->getYcanonDefensivo()+vyo*aux-(0.5*g*(aux*aux))+40;
             balaOf.at(i)->setPosx(auxX);
             balaOf.at(i)->setPosy(auxY);
             balaOf.at(i)->setPos(auxX,auxY);
             scene->addItem(balaOf.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}
//ingresan los datos para poner en la escena la secuencia de balas
void lanzador2::grafica2(int t, int V0o, int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;

            num=t/10.0;

         for (int i = 0 ; i <balaOf2.size(); i++) {
                aux += num;
             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonDefensivo()+(V0o*-cos(angle*pi/180)*aux))-40;
             auxY = this->getYcanonDefensivo()+vyo*aux-(0.5*g*(aux*aux))+40;
             balaOf2.at(i)->setPosx(auxX);
             balaOf2.at(i)->setPosy(auxY);
             balaOf2.at(i)->setPos(auxX,auxY);
             scene->addItem(balaOf2.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}
//ingresan los datos para poner en la escena la secuencia de balas
void lanzador2::grafica3(int t, int V0o, int angle)
{
    float aux =0, auxX,auxY,g = 9.81,  pi =3.1416, vyo;
    double num;
            num=t/10.0;//a el tiempo lo dividimos en 10 para que las 10 balas esten separadas por la misma distancia

         for (int i = 0 ; i <balaOf3.size(); i++) {
                aux += num;

             vyo= V0o*sin(angle*pi/180)-g*aux;
             auxX = (this->getXcanonDefensivo()+(V0o*-cos(angle*pi/180)*aux))-40;
             auxY = this->getYcanonDefensivo()+vyo*aux-(0.5*g*(aux*aux))+40;
             balaOf3.at(i)->setPosx(auxX);
             balaOf3.at(i)->setPosy(auxY);
             balaOf3.at(i)->setPos(auxX,auxY);

             scene->addItem(balaOf3.at(i));
             qDebug()<<"creada una X: "<<auxX<< "Y: "<<auxY<<"aux: "<<aux;

         }
}
//creamos la lista de balas defensivas
QList<balad *> lanzador2::diez_bolas()
{
    QList<balad*>bala;
    balad* bala1 = new balad();
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
