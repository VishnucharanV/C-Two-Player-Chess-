#include <iostream>
#include <conio.h>
using namespace std;
struct piece{
	string name;
	int x;
	int y;
	bool color;
};

void game(int t,piece pieces[8][8]);
bool eval(string name,bool color,int x1,int y1,int x2,int y2,piece pieces[8][8],bool turn);
bool check(int x1,int x2,bool color,piece pieces[8][8]);
void display(piece pieces[8][8]);
int main(){
	piece pieces[8][8];
	for(int i=2;i<6;i++){
		for(int j=0;j<8;j++){
			piece ex;
			ex.name="null";
			ex.x=j;
			ex.y=i;
			if((i+j)%2==0){
				ex.color=0;
			}
			else{
				ex.color=1;
			}
			pieces[j][i]=ex;
		}
	}
	piece ex1,ex2,ex3,ex4,ex5,ex6;
	// i) PAWN
	ex6.name="pawn";
	ex6.color=1;
	ex6.x=1;
	for(int i=0;i<8;i++){
		pieces[i][ex6.x]=ex6;
	}
	ex6.color=0;
	ex6.x=6;
	for(int i=0;i<8;i++){
		pieces[i][ex6.x]=ex6;
	}
	// ii)ROOK
	ex5.name="rook";
	ex5.color=1;
	ex5.x=0;
	ex5.y=0;
	pieces[0][0]=ex5;
	ex5.x=7;
	ex5.y=0;
	pieces[7][0]=ex5;
	ex5.x=7;
	ex5.y=7;
	ex5.color=0;
	pieces[7][7]=ex5;
	ex5.y=7;
	pieces[0][7]=ex5;
	
	// iii)Knight
	ex4.name="knight";
	ex4.color=1;
	ex4.x=1;
	ex4.y=0;
	pieces[1][0]=ex4;
	ex4.x=6;
	pieces[6][0]=ex4;
	ex4.color=0;
	ex4.y=7;
	pieces[6][7]=ex4;
	ex4.x=1;
	pieces[1][7]=ex4;
	
	// iv)Bishop
	ex3.name="bishop";
	ex3.color=1;
	ex3.x=2;
	ex3.y=0;
	pieces[2][0]=ex3;
	ex3.x=5;
	pieces[5][0]=ex3;
	ex3.color=0;
	ex3.y=7;
	pieces[5][7]=ex3;
	ex3.x=2;
	pieces[2][7]=ex3;	
	
	// v)Queen
	ex2.name="queen";
	ex2.color=1;
	ex2.x=3;
	ex2.y=0;
	pieces[3][0]=ex2;
	ex2.color=0;
	ex2.x=4;
	ex2.y=7;
	pieces[4][7]=ex2;	
	
	//vi)King
	ex1.name="king";
	ex1.color=1;
	ex1.x=4;
	ex1.y=0;
	pieces[4][0]=ex1;
	ex1.color=0;
	ex1.x=5;
	ex1.y=7;
	pieces[3][7]=ex1;
	int n;
	cout<<"Choose your colors before starting the game\n";
	cout<<"Player 1: White\nPlayer2: Black\n";
	cout<<"Player can withdraw From the Game only after 1st Move!\n";
	cout<<"Let the game Begin!\n";
	for(int i=7;i>=0;i--){
		cout<<"________________________________________________________________________________\n";
		for(int j=0;j<8;j++){
			if(j!=7){
				if(pieces[j][i].name=="bishop"||pieces[j][i].name=="knight"){
					cout<<"| "<<pieces[j][i].color<<pieces[j][i].name<<" ";
				}
				else if(pieces[j][i].name=="king"||pieces[j][i].name=="pawn"||pieces[j][i].name=="null"||pieces[j][i].name=="rook"){
					cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<"  ";
				}
				else{
					cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" ";
				}
			}
			else{
				if(pieces[j][i].name=="bishop"||pieces[j][i].name=="knight"){
					cout<<"| "<<pieces[j][i].color<<pieces[j][i].name<<" |";
				}
				else if(pieces[j][i].name=="king"||pieces[j][i].name=="pawn"||pieces[j][i].name=="null"||pieces[j][i].name=="rook"){
					cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" |";
				}
				else{
					cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" |";
				}			
			}
		}
		cout<<"\n";
	}
	cout<<"________________________________________________________________________________\n";
	cout<<"\n\n\n";
	int t=0;
	game(t,pieces); 
}

void game(int t,piece pieces[8][8]){
	int x1,y1,x2,y2;
	char ch='n';
	do{
		int ulflag1=0,ulflag2=0;
		if(t%2==0){
			cout<<"It's Player1's turn\n";
			if(t>1){
			cout<<"Do you wish to withdraw ? (y/n)";
			cin>>ch;
			}
			cout<<"Coin you wish to move :\n";
			cout<<"Coin x position : ";
			cin>>x1;
			cout<<"Coin y position : ";
			cin>>y1;
			cout<<"Coin : "<<pieces[x1][y1].name<<"\n";
			string name1=pieces[x1][y1].name;
			bool color1=pieces[x1][y1].color;
			cout<<"Where do you wish to move : \n";
			cout<<"Final x position : ";
			cin>>x2;
			cout<<"Final y position : ";
			cin>>y2;
			bool t1 = eval(name1,color1,x1,y1,x2,y2,pieces,1);
			
			if(t1){
				cout<<"Move Made!\n";
				t+=1;
				for(int i1=7;i1>=0;i1--){
					for(int j1=0;j1<8;j1++){
						if(pieces[j1][i1].name=="king" && pieces[j1][i1].color==0){
							ulflag1=1;
							break;
						}
					}
				}
				if(!ulflag1){
					cout<<"\n\n---------- PLAYER 1 WINS ----------\n\n";
					cout<<"----- GAME OVER -----\n";
					break;
				}
			}
			else{
				cout<<"Cannot make that Move!!\n";
			}
			
		}
		else{
			cout<<"It's Player2's turn\n";
			if(t>1){
			cout<<"Do you wish to withdraw ? (y/n)";
			cin>>ch;
			}
			cout<<"Coin you wish to move :\n";
			cout<<"Coin x position : ";
			cin>>x1;
			cout<<"Coin y position : ";
			cin>>y1;
			cout<<"Coin : "<<pieces[x1][y1].name<<"\n";
			string name1=pieces[x1][y1].name;
			bool color1=pieces[x1][y1].color;
			cout<<"Where do you wish to move : \n";
			cout<<"Final x position : ";
			cin>>x2;
			cout<<"Final y position : ";
			cin>>y2;
			bool t1 = eval(name1,color1,x1,y1,x2,y2,pieces,0);
			if(t1){
				cout<<"Move Made!!\n";
				t+=1;
				for(int i1=7;i1>=0;i1--){
					for(int j1=0;j1<8;j1++){
						if(pieces[j1][i1].name=="king" && pieces[j1][i1].color==1){
							ulflag2=1;
							break;
						}
					}
				}
				if(!ulflag2){
					cout<<"\n\n---------- PLAYER 2 WINS ----------\n\n";
					cout<<"----- GAME OVER -----\n";
					break;
				}
			}
			else{
				cout<<"Cannot make that Move!\n";
			}
		}
		for(int i=7;i>=0;i--){
			cout<<"________________________________________________________________________________\n";
			for(int j=0;j<8;j++){
				if(j!=7){
					if(pieces[j][i].name=="bishop"||pieces[j][i].name=="knight"){
						cout<<"| "<<pieces[j][i].color<<pieces[j][i].name<<" ";
					}
					else if(pieces[j][i].name=="king"||pieces[j][i].name=="pawn"||pieces[j][i].name=="null"||pieces[j][i].name=="rook"){
						cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<"  ";
					}
					else{
						cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" ";
					}
				}
				else{
					if(pieces[j][i].name=="bishop"||pieces[j][i].name=="knight"){
						cout<<"| "<<pieces[j][i].color<<pieces[j][i].name<<" |";
					}
					else if(pieces[j][i].name=="king"||pieces[j][i].name=="pawn"||pieces[j][i].name=="null"||pieces[j][i].name=="rook"){
						cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" |";
					}
					else{
						cout<<"|  "<<pieces[j][i].color<<pieces[j][i].name<<" |";
					}			
				}
			}
			cout<<"\n";
		}
		cout<<"________________________________________________________________________________\n";
		cout<<"\n\n\n";
	}while(ch=='n');
}

bool eval(string name,bool color,int x1,int y1,int x2,int y2,piece pieces[8][8],bool turn){
	if(pieces[x1][y1].color==turn){
	if(x2>7 or x2<0 or y2>7 or y2<0){
		return 0;
	}
	else{
		if(name=="pawn"){
			if(turn==1){
				if(x2==x1){
					if(pieces[x2][y2].name!="null"){
						return 0;
					}
					else{
						if((y2-y1)!=1){
							return 0;
						}
						else{
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
				else{
					if((x2-x1)==-1 or (x2-x1)==1){
						if((y2-y1)==1){
							if(pieces[x2][y2].name!="null" && pieces[x2][y2].color==color){
								return 0;
							}
							else{
								if(pieces[x2][y2].name=="null"){
									return 0;
								}
								else{
									cout<<"Knock out Move!\n";
									cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
									piece intermed = pieces[x1][y1];
									pieces[x2][y2]=intermed;
									pieces[x1][y1].name="null";
									if((x1+y1)%2==0){
										pieces[x1][y1].color=0;
									}
									else{
										pieces[x1][y1].color=1;
									}
									return 1;	
								}
							}
						}
						else{
							return 0;
						}
					}
					else{
						return 0;
					}
				}
			}
			else{
				if(x2==x1){
					if(pieces[x2][y2].name!="null"){
						return 0;
					}
					else{
						if((y1-y2)!=1){
							return 0;
						}
						else{
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
				else{
					if((x2-x1)==-1 or (x2-x1)==1){
						if((y1-y2)==1){
							if(pieces[x2][y2].name!="null" && pieces[x2][y2].color==color){
								return 0;
							}
							else{
								if(pieces[x2][y2].name=="null"){
									return 0;
								}
								else{
									cout<<"Knock out Move!\n";
									cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
									piece intermed = pieces[x1][y1];
									pieces[x2][y2]=intermed;
									pieces[x1][y1].name="null";
									if((x1+y1)%2==0){
										pieces[x1][y1].color=0;
									}
									else{
										pieces[x1][y1].color=1;
									}
									return 1;	
								}
							}
						}
						else{
							return 0;
						}
					}
					else{
						return 0;
					}
				}
			}
		}
		else if(name=="knight"){
			if(abs(x2-x1)*abs(y2-y1)==2){
				if(pieces[x2][y2].name!="null" and pieces[x2][y2].color==color){
					return 0;
				}
				else{
					if(pieces[x2][y2].name=="null"){
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
					else{
						cout<<"Knock out Move!\n";
						cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
				}
			}
			else{
				return 0;
			}
		}
		else if(name=="rook")
		{
			int flag1=0;
			if(x1==x2 or y2==y1){
				if(x1==x2){
					for(int i=y1+1;i<y2;i++){
						if(pieces[x1][i].name!="null"){
							flag1=1;
							break;
						}
					}
				}
				else if(y2==y1){
					for(int i=x1+1;i<x2;i++){
						if(pieces[i][y1].name!="null"){
							flag1=1;
							break;
						}
					}
				}
				if(flag1==1){
					flag1=0;
					cout<<flag1;
					return 0;
				}
				else{
					if(pieces[x2][y2].name!="null" && pieces[x2][y2].color!=color){
						cout<<"Knock out Move!\n";
						cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
					else{
						if(pieces[x2][y2].name!="null" && pieces[x2][y2].color==color){
							return 0;
						}
						else if(pieces[x2][y2].name=="null"){
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
			}
			else{
				return 0;
			}
		}
		else if(name=="bishop"){
			int flag2=0;
			if(abs(x1-x2)==abs(y1-y2)){
				if(x2>x1){
					if(y2>y1){
						for(int i=1;i<x2-x1;i++){
							if(pieces[x1+i][y1+i].name!="null"){
								flag2=1;
								break;
							}
						}
					}
					else{
						for(int i=1;i<x2-x1;i++){
							if(pieces[x1+i][y1-i].name!="null"){
								flag2=1;
								break;
							}
						}
					}
				}
				else{
					if(y2>y1){
						for(int i=1;i<x1-x2;i++){
							if(pieces[x1-i][y1+i].name!="null"){
								flag2=1;
								break;
							}
						}
					}
					else{
						for(int i=1;i<x1-x2;i++){
							if(pieces[x1-i][y1-i].name!="null"){
								flag2=1;
								break;
							}
						}
					}
				}
				if(flag2==1){
					flag2=0;
					return 0;
				}
				else{
					if(pieces[x2][y2].name!="null" && pieces[x2][y2].color!=color){
						cout<<"Knock out move!\n";
						cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
					else{
						if(pieces[x2][y2].color==color && pieces[x2][y2].name!="null"){
							return 0;
						}
						else{
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
			}
			else{
				
				return 0;
			}
		}
		else if(name=="queen"){
			int flag3=0;
			if(x1==x2 or y2==y1){
				if(x1==x2){
					for(int i=y1+1;i<y2;i++){
						if(pieces[x1][i].name!="null"){
							flag3=1;
							break;
						}
					}
				}
				else if(y2==y1){
					for(int i=x1+1;i<x2;i++){
						if(pieces[i][y1].name!="null"){
							flag3=1;
							break;
						}
					}
				}
				if(flag3==1){
					flag3=0;
					return 0;
				}
				else{
					if(pieces[x2][y2].name!="null" && pieces[x2][y2].color!=color){
						cout<<"Knock out move!\n";
						cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
					else{
						if(pieces[x2][y2].color==color && pieces[x2][y2].name!="null"){
							return 0;
						}
						else{
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
			}
			else if(abs(x1-x2)==abs(y1-y2)){
				if(x2>x1){
					if(y2>y1){
						for(int i=1;i<x2-x1;i++){
							if(pieces[x1+i][y1+i].name!="null"){
								flag3=1;
								break;
							}
						}
					}
					else{
						for(int i=1;i<x2-x1;i++){
							if(pieces[x1+i][y1-i].name!="null"){
								flag3=1;
								break;
							}
						}
					}
				}
				else{
					if(y2>y1){
						for(int i=1;i<x1-x2;i++){
							if(pieces[x1-i][y1+i].name!="null"){
								flag3=1;
								break;
							}
						}
					}
					else{
						for(int i=1;i<x1-x2;i++){
							if(pieces[x1-i][y1-i].name!="null"){
								flag3=1;
								break;
							}
						}
					}
				}
				if(flag3==1){
					flag3=0;
					cout<<flag3;
					return 0;
				}
				else{
					if(pieces[x2][y2].name!="null" && pieces[x2][y2].color!=color){
						cout<<"Knock out move!\n";
						cout<<"Knocked out : "<<pieces[x2][y2].name<<"\n";
						piece intermed = pieces[x1][y1];
						pieces[x2][y2]=intermed;
						pieces[x1][y1].name="null";
						if((x1+y1)%2==0){
							pieces[x1][y1].color=0;
						}
						else{
							pieces[x1][y1].color=1;
						}
						return 1;
					}
					else{
						if(pieces[x2][y2].color==color && pieces[x2][y2].name!="null"){
							return 0;
						}
						else{
							piece intermed = pieces[x1][y1];
							pieces[x2][y2]=intermed;
							pieces[x1][y1].name="null";
							if((x1+y1)%2==0){
								pieces[x1][y1].color=0;
							}
							else{
								pieces[x1][y1].color=1;
							}
							return 1;
						}
					}
				}
			}
			else{
				return 0;
			}
		}
		else if(name=="king"){
			if(((x2==x1 || y2==y1) && (abs(x2-x1)+abs(y2-y1)==1)) || (abs(x2-x1)+abs(y2-y1)==2)){
				if(pieces[x2][y2].name!="null" && pieces[x2][y2].color==color){
					return 0;
				}
				if(check(x2,y2,color,pieces)){
					return 0;
				}
				else{
					piece intermed = pieces[x1][y1];
					pieces[x2][y2]=intermed;
					pieces[x1][y1].name="null";
					if((x1+y1)%2==0){
						pieces[x1][y1].color=0;
					}
					else{
						pieces[x1][y1].color=1;
					}
					return 1;
				}
			}
			else{
				return 0;
			}
		}
	}
	}
	else{
		return 0;
	}
}

bool check(int x,int y,bool color,piece pieces[8][8]){
	bool u=0,d=0,l=0,r=0,ur=0,ul=0,dr=0,dl=0;
	for(int i=1;i<8;i++){
		if(x+i>7 || y+i>7){
			break;
		}
		else{
			if(pieces[x+i][y+i].color==color && pieces[x+i][y+i].name!="null"){
				break;
			}
			else if((pieces[x+i][y+i].name=="queen" || pieces[x+i][y+i].name=="bishop") && pieces[x+i][y+i].color!=color){
				ur=1;
				break;
			}
		}
	}
	for(int i=1;i<8;i++){
		if(x+i>7 || y-i<0){
			break;
		}
		else{
			if(pieces[x+i][y-i].color==color && pieces[x+i][y-i].name!="null"){
				break;
			}
			else if((pieces[x+i][y-i].name=="queen" || pieces[x+i][y-i].name=="bishop") && pieces[x+i][y-i].color!=color){
				dr=1;
				break;
			}
		}
	}
	for(int i=1;i<8;i++){
		if(x-i<0 || y+i>7){
			break;
		}
		else{
			if(pieces[x-i][y+i].color==color && pieces[x-i][y+i].name!="null"){
				break;
			}
			else if((pieces[x-i][y+i].name=="queen" || pieces[x-i][y+i].name=="bishop") && pieces[x-i][y+i].color!=color){
				ul=1;
				break;
			}
		}
	}
	for(int i=1;i<8;i++){
		if(x-i<0 || y-i<0){
			break;
		}
		else{
			if(pieces[x-i][y-i].color==color && pieces[x-i][y-i].name!="null"){
				break;
			}
			else if((pieces[x-i][y-i].name=="queen" || pieces[x-i][y-i].name=="bishop") && pieces[x-i][y-i].color!=color){
				dl=1;
				break;
			}
		}
	}
	if(x==0){
		if(y!=7){
			if(pieces[x+1][y+1].name=="pawn" && pieces[x+1][y+1].color!=color){
				ur=1;
			}
			else if(pieces[x+1][y+1].name=="king" && pieces[x+1][y+1].color!=color){
				ur=1;
			}
			else if(pieces[x+1][y].name=="king" && pieces[x+1][y].color!=color){
				r=1;
			}
			else if(pieces[x][y+1].name=="king" && pieces[x][y+1].color!=color){
				u=1;
			}
			if(y!=0){
				if(pieces[x+1][y-1].name=="king" && pieces[x+1][y-1].color!=color){
					dr=1;
				}
				else if(pieces[x][y-1].name=="king" && pieces[x][y-1].color!=color){
					d=1;
				}		
			}
		}
	}
	else if(x==7){
		if(y!=7){
			if(pieces[x-1][y+1].name=="pawn" && pieces[x-1][y+1].color!=color){
				ul=1;
			}
			else if(pieces[x-1][y+1].name=="king" && pieces[x-1][y+1].color!=color){
				ul=1;
			}
			else if(pieces[x-1][y].name=="king" && pieces[x-1][y].color!=color){
				l=1;
			}
			else if(pieces[x][y+1].name=="king" && pieces[x][y+1].color!=color){
				u=1;
			}
			if(y!=0){
				if(pieces[x-1][y-1].name=="king" && pieces[x-1][y-1].color!=color){
					dl=1;
				}
				else if(pieces[x][y-1].name=="king" && pieces[x][y-1].color!=color){
					d=1;
				}				
			}	
		}
	}
	else{
		if(y!=7){
			if((pieces[x+1][y+1].name=="pawn" && pieces[x+1][y+1].color!=color)){
				ur=1;
			}
			else if((pieces[x-1][y+1].name=="pawn" && pieces[x-1][y+1].color!=color)){
				ul=1;
			}
		}
		if(y!=0 && y!=7){
			if(pieces[x-1][y+1].name=="king" && pieces[x-1][y+1].color!=color){
				ul=1;
			}
			else if(pieces[x-1][y].name=="king" && pieces[x-1][y].color!=color){
				l=1;
			}
			else if(pieces[x][y+1].name=="king" && pieces[x][y+1].color!=color){
				u=1;
			}
			else if(pieces[x+1][y+1].name=="king" && pieces[x+1][y+1].color!=color){
				ur=1;
			}
			else if(pieces[x+1][y].name=="king" && pieces[x+1][y].color!=color){
				r=1;
			}
			else if(pieces[x-1][y-1].name=="king" && pieces[x-1][y-1].color!=color){
				dl=1;
			}
			else if(pieces[x][y-1].name=="king" && pieces[x][y-1].color!=color){
				d=1;
			}
			else if(pieces[x+1][y-1].name=="king" && pieces[x+1][y-1].color!=color){
				dr=1;
			}	
		}
		else if(y==0){
			if(pieces[x-1][y+1].name=="king" && pieces[x-1][y+1].color!=color){
				ul=1;
			}
			else if(pieces[x-1][y].name=="king" && pieces[x-1][y].color!=color){
				l=1;
			}
			else if(pieces[x][y+1].name=="king" && pieces[x][y+1].color!=color){
				u=1;
			}
			else if(pieces[x+1][y+1].name=="king" && pieces[x+1][y+1].color!=color){
				ur=1;
			}
			else if(pieces[x+1][y].name=="king" && pieces[x+1][y].color!=color){
				r=1;
			}	
		}
		else if(y==7){
			if(pieces[x+1][y].name=="king" && pieces[x+1][y].color!=color){
				r=1;
			}
			else if(pieces[x-1][y-1].name=="king" && pieces[x-1][y-1].color!=color){
				dl=1;
			}
			else if(pieces[x][y-1].name=="king" && pieces[x][y-1].color!=color){
				d=1;
			}
			else if(pieces[x+1][y-1].name=="king" && pieces[x+1][y-1].color!=color){
				dr=1;
			}
			else if(pieces[x-1][y].name=="king" && pieces[x-1][y].color!=color){
				l=1;
			}
		}
	}
	for(int i=0;i<8;i++){
		if(x+i>7){
			break;
		}
		else{
			if((pieces[x+i][y].name=="queen" || pieces[x+i][y].name=="rook") && (pieces[x+i][y].color!=color)){
				r=1;
				break;
			}
		}
	}
	for(int i=0;i<8;i++){
		if(x-i<0){
			break;
		}
		else{
			if((pieces[x-i][y].name=="queen" || pieces[x-i][y].name=="rook") && (pieces[x-i][y].color!=color)){
				l=1;
				break;
			}
		}
	}
	for(int i=0;i<8;i++){
		if(y+i>7){
			break;
		}
		else{
			if((pieces[x][y+i].name=="queen" || pieces[x][y+i].name=="rook") && (pieces[x][y+i].color!=color)){
				u=1;
				break;
			}
		}
	}
	for(int i=0;i<8;i++){
		if(y-i>7){
			break;
		}
		else{
			if((pieces[x][y-i].name=="queen" || pieces[x][y-i].name=="rook") && (pieces[x][y-i].color!=color)){
				d=1;
				break;
			}
		}
	}
	if(u==1 && d==1 && r==1 && l==1 && ur==1 && ul==1 && dr==1 && dl==1){
		return 1;
	}
	else{
		cout<<u<<d<<r<<l<<ur<<ul<<dr<<dl;
		return 0;
	}
}

