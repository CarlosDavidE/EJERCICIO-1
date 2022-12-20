#include <iostream>
using namespace std;
int main (){
	int a,i=1,a1,a2,a5,a6,a7,a8;
	int p1=2, p2=1, p3=50;
	cout<<"Realice el caso de la maquina de refrescos. El refresco cuesta 2 soles, y se posee monedas"<<endl;
	cout<<"de 0.50 soles, 1 sol y 2 soles.\n";
	cout<<"----------------------------------------------------------------------------------------------------\n";
	cout<<"INGRESE UNA MONEDA\n";
	cout<<"VALOR DEL REFRESCO: S/2.00\n";
	cout<<"MONEDAS QUE SON ACEPTADAS: S/1.00    S/2.00     S/0.50 \n";
	cout<<".............................................................\n";

	
	cout<<"MONEDA A INGRESAR: S/";
	cin>>a;
	if(a==50){
		int x=1;
		while(x==1){
			cout<<"REFRESCO= S/2.00"<<endl;
			cout<<"SALDO S/0."<<a<<endl;
			cout<<"......INGRESE : ";
			cin>>a5;
			if(a5==1){         
				int y=1;
				while(y==1){
					cout<<"REFRESCO= S/2.00"<<endl;
					cout<<"SALDO S/"<<a5<<"."<<a<<endl;
					cout<<"INGRESE MONEDA: ";
					cin>>a6;
					if(a6==50){ 
						cout<<"....GRACIAS POR SU COMPRA....\n";
						cout<<"........CADENA VALIDA........\n";
						return 0;
					}else{
						cout<<"MONEDA NO ACEPTADA\n";
						cout<<"MONEDA DEVUELTA: "<<a6<<endl;
						y=1;
					}	
				}
			}else{             //50
				if(a5==50){
					int z=1;
					while(z==1){
						cout<<"REFRESCO= S/2.00"<<endl;
					    cout<<"SALDO S/1.00"<<endl;
					    cout<<"INGRESE MONEDA: ";
						cin>>a7;
						if(a7==1){
							cout<<"....GRACIAS POR SU COMPRA....\n";
						    cout<<"........CADENA VALIDA........\n";
							return 0;		
						}else{
							if(a7==50){
								int w=1;
								while(w=1){
									cout<<"REFRESCO= S/2.00"<<endl;
					                cout<<"SALDO S/1.50"<<endl;
					                cout<<"INGRESE MONEDA: ";
									cin>>a8;
									if(a8==50){
										cout<<"....GRACIAS POR SU COMPRA....\n";
						                cout<<"........CADENA VALIDA........\n";
										return 0;
									}else{
										cout<<"MONEDA NO ACEPTADA\n";
						                cout<<"MONEDA DEVUELTA: "<<a5<<endl;
										w=1;	
									}
								}
							}else{
								cout<<"MONEDA NO ACEPTADA\n";
						        cout<<"MONEDA DEVUELTA: "<<a5<<endl;
								z=1;	
							}
						}
							
					}
					
				}else{
					cout<<"MONEDA NO ACEPTADA\n";
					cout<<"MONEDA DEVUELTA: "<<a5<<endl;
					x=1;
				}
			}
		}
	}
	
	while(i==1){
		if(a==p1){														
			cout<<"....GRACIAS POR SU COMPRA....\n";
	        cout<<"........CADENA VALIDA........\n";
			return 0;
		}else{
			if(a==p2){															 
				cout<<"REFRESCO= S/2.00"<<endl;
				cout<<"SALDO S/"<<a<<endl;
				cout<<"INGRESE MONEDA: ";
				cin>>a1;
				if(a1==p2){ 														
					cout<<"....GRACIAS POR SU COMPRA....\n";
	                cout<<"........CADENA VALIDA........\n";
					return 0;
				}else{
					if(a1==p3){                 									//1 50 = 1.50
						cout<<"REFRESCO= S/2.00"<<endl;
						cout<<"SALDO S/"<<a<<"."<<a1<<endl;
						cout<<"INGRESE MONEDA: ";
						cin>>a2;
						if(a2==p3){														//1.50 50 = 2
							cout<<"....GRACIAS POR SU COMPRA....\n";
	                        cout<<"........CADENA VALIDA........\n";
							return 0;
						}else{
							while(a2 != 50){// error hasta que ingrese 50
								cout<<"MONEDA NO ACEPTADA\n";
								cout<<"MONEDA DEVUELTA: "<<a2<<endl;
								cout<<"SALDO S/"<<a<<".50"<<endl;
								cout<<"INGRESE UNA MONEDA VALIDA: ";
								cin>>a2;
							}
							cout<<"....GRACIAS POR SU COMPRA....\n";
	                        cout<<"........CADENA VALIDA........\n";
							return 0;								
						}															
					}else{
						while(a1!=p3){// error hasta que ingrese 50
							cout<<"MONEDA NO ACEPTADA\n";
							cout<<"MONEDA DEVUELTA: "<<a1<<endl;
							cout<<"SALDO S/"<<a<<".00\n";
							cout<<"INGRESE UNA MONEDA VALIDA: ";
							cin>>a1;
						}
						cout<<"REFRESCO= S/2.00\n";
						cout<<"SALDO S/"<<a<<"."<<a1<<endl;
						cout<<"INGRESE MONEDA: ";
						cin>>a2;
						if(a2==p3){														//1.50 50 = 2
							cout<<"....GRACIAS POR SU COMPRA....\n";
	                        cout<<"........CADENA VALIDA........\n";
							return 0;
						}else{
							while(a2 != 50){											// error hasta que ingrese 50
								cout<<"MONEDA NO ACEPTADA\n";
								cout<<"MONEDA DEVUELTA: "<<a2<<endl;
								cout<<"SALDO S/"<<a<<"."<<a2<<"\n";
								cout<<"INGRESE UNA MONEDA VALIDA :";
								cin>>a2;
							}
							cout<<"....GRACIAS POR SU COMPRA....\n";
	                        cout<<"........CADENA VALIDA........\n";
							return 0;								
						}						
						
					}
				}
				i==2;	
			}else{
				cout<<"MONEDA NO ACEPTADA\n";
				cout<<"MONEDA DEVUELTA: "<<a;
				cout<<"INGRESE UNA MONEDA VALIDA: ";
				cin>>a;
				i==1;
				
			}
		}
	}
	return 0;
}
