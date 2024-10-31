int main(){
    int numeroCuotas;
    float monto;
    cout<<"Ingrese el numero de cuotas: ";
    cin>>numeroCuotas;
    cout<<"Ingrese el monto: ";
    cin>>monto;
    if(numeroCuotas>36 || monto>2000){
        cout<<"Valores no validos"<<endl;
    }else{
        cout<<"El monto total es de: "<<monto*numeroCuotas<<" Bs."<<endl;
    }
    return 0;
}
