class Polynomial {
    
    public:
    int *Coeff_and_deg;      // Name of array 
    int total_size;
    
    //default constructor
    Polynomial(){
        this->Coeff_and_deg=new int[6];  // element of array represents coeff. and associated index represents degree
        this->total_size=5;
    }
    //paramaterized constructor
    Polynomial (int total_size){
        this->Coeff_and_deg=new int[total_size+1];
        this->total_size=total_size;
    }
    
    //copy constructor
    Polynomial (Polynomial const &p){
        int *newdeg=new int[p.total_size+1];
            
        for(int i=0;i<=p.total_size;i++)
            newdeg[i]=p.Coeff_and_deg[i];
            
        this->Coeff_and_deg=newdeg;
        
        this->total_size=p.total_size;
    }
    
    void setCoefficient(int deg,int coef){
        if(deg>total_size){
            int newcapacity=deg;
            int *newdeg=new int[newcapacity+1];
            //Copy the contents from original to new
            for(int i=0;i<=total_size;i++)
                newdeg[i]=Coeff_and_deg[i];
            
            this->Coeff_and_deg=newdeg;
            this->total_size=newcapacity;
            //Set the new coeff;
            Coeff_and_deg[deg]=coef;
        }
        else{
            Coeff_and_deg[deg]=coef;
        }
    }
    
    Polynomial operator+(Polynomial const &P2){
        
        int newcap=max(this->total_size,P2.total_size);
        
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=total_size && i<=P2.total_size)
                P3.Coeff_and_deg[i]=this->Coeff_and_deg[i]+P2.Coeff_and_deg[i];
            else if(i<=total_size)
                P3.Coeff_and_deg[i]=this->Coeff_and_deg[i];
            else 
                P3.Coeff_and_deg[i]=P2.Coeff_and_deg[i];
        }
        
        return P3;
    }
    
    Polynomial operator-(Polynomial const &P2){
        
        int newcap=max(this->total_size,P2.total_size);
        Polynomial P3(newcap);
        
        for(int i=0;i<=newcap;i++){
            if(i<=total_size && i<=P2.total_size)
                P3.Coeff_and_deg[i]=this->Coeff_and_deg[i]-P2.Coeff_and_deg[i];
            else if(i<=total_size)
                P3.Coeff_and_deg[i]=this->Coeff_and_deg[i];
            else 
                P3.Coeff_and_deg[i]=-P2.Coeff_and_deg[i];
        }
        
        return P3;
    }
    
    Polynomial operator*(Polynomial const &P2){
        
        int newcap=this->total_size+P2.total_size;
        Polynomial P3(newcap);
        
        for(int i=0;i<=this->total_size;i++){
            
            for(int j=0;j<=P2.total_size;j++){
                P3.Coeff_and_deg[i+j]+=this->Coeff_and_deg[i]*P2.Coeff_and_deg[j];
            }
        }
        return P3;
    }
    
    void operator=(Polynomial const &p){
        int *newdeg=new int[p.total_size+1];
        //Copy the contents
        for(int i=0;i<p.total_size;i++)
            newdeg[i]=p.Coeff_and_deg[i];
            
        
        this->Coeff_and_deg=newdeg;
        
        this->total_size=p.total_size;
    }
    
    void print(){
        
        for(int i=0;i<=this->total_size;i++){
            if(Coeff_and_deg[i]!=0)
                cout<<Coeff_and_deg[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
           
};


#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int N,M,C;
    cin >> N; // total number of terms in polynomial P1

    int *degree1 = new int[N];  
    int *coeff1 = new int[N];
    
    for(int i=0;i < N; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < N; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial p1;
    for(int i = 0; i < N; i++){
        p1.setCoefficient(degree1[i],coeff1[i]);
    }


   // ==============================================================================
    

    cin >> M;//total number of terms in polynomial P2
    
    int *degree2 = new int[M];
    int *coeff2 = new int[M];
    
    for(int i=0;i < M; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < M; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial p2;
    for(int i = 0; i < M; i++){
        p2.setCoefficient(degree2[i],coeff2[i]);
    }
    
    //================================================================================


    cin >> C;  // represents choice of which function to be called
    
    switch(C){

        case 1 : // Copy constructor
        {
            Polynomial third(p1);
            if(third.Coeff_and_deg == p1.Coeff_and_deg) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            // Add
        case 2:
        {
            Polynomial result1 = p1 + p2;
            result1.print();
            break;
        }
            // Subtract
        case 3 :
        {
            Polynomial result2 = p1 - p2;
            result2.print();
            break;
        }
            // Multiply
        case 4 :
        {
            Polynomial result3 = p1 * p2;
            result3.print();
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(p1);
            if(fourth.Coeff_and_deg == p1.Coeff_and_deg) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}