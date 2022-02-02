#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
long long sc,hsc;
int Map[5][5];
void HideCurSor(void){
	CONSOLE_CURSOR_INFO info={1,0};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(Out,&info);
}
void SetPos(int j,int i)
{
	COORD pos={8*i-6,4*j-2};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void Set()
{
	COORD pos={0,0};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void SetPos2(int i,int j)
{
	COORD pos={i,j};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void draw() {
	Set();
	printf("©³©¥©¥©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©¥©¥©·\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©Ç©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©Ï\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©Ç©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©Ï\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©Ç©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©¥©¥©Ï\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©§       ©§       ©§       ©§       ©§\n");
	printf("©»©¥©¥©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©¥©¥©¿\n");
}
void write() {
	for(int i=1;i<=4;++i) {
		for(int j=1;j<=4;++j) {
			SetPos(i,j);
			if(Map[i][j]) printf("%6d",Map[i][j]);
		}
	}
}
bool check_up() {
	for(int j=1;j<=4;++j) {
		bool space=false;
		for(int i=1;i<=4;++i) {
			if(!Map[i][j]) space=true;
			if(space&&Map[i][j]) return true;
			if(i<=3&&Map[i][j]&&Map[i][j]==Map[i+1][j]) return true;
		}
	}
	return false;
}
bool check_down() {
	for(int j=1;j<=4;++j) {
		bool space=false;
		for(int i=4;i>=1;--i) {
			if(!Map[i][j]) space=true;
			if(space&&Map[i][j]) return true;
			if(i>=2&&Map[i][j]&&Map[i][j]==Map[i-1][j]) return true;
		}
	}
	return false;
}
bool check_left() {
	for(int i=1;i<=4;++i) {
		bool space=false;
		for(int j=1;j<=4;++j) {
			if(!Map[i][j]) space=true;
			if(space&&Map[i][j]) return true;
			if(j<=3&&Map[i][j]&&Map[i][j]==Map[i][j+1]) return true;
		}
	}
	return false;
}
bool check_right() {
	for(int i=1;i<=4;++i) {
		bool space=false;
		for(int j=4;j>=1;--j) {
			if(!Map[i][j]) space=true;
			if(space&&Map[i][j]) return true;
			if(j>=2&&Map[i][j]&&Map[i][j]==Map[i][j-1]) return true;
		}
	}
	return false;
}
void move_up() {
	for(int j=1;j<=4;++j) {
		for(int i=2;i<=4;++i) {
			bool bl=true;
			for(int k=i;k<=4;++k) {
				if(Map[k][j]) bl=false;
			}
			if(bl) continue;
			if(Map[i-1][j]==0) {
				for(int k=i;k<=4;++k) {
					Map[k-1][j]=Map[k][j];
				}
				Map[4][j]=0;
				--i;
			}
		}
		for(int i=2;i<=4;++i) {
			if(Map[i-1][j]==Map[i][j]) {
				Map[i-1][j]+=Map[i][j];
				sc+=Map[i-1][j];
				for(int k=i+1;k<=4;++k) {
					Map[k-1][j]=Map[k][j];
				}
				Map[4][j]=0;
			}
		}
	}
}
void move_down() {
	for(int j=1;j<=4;++j) {
		for(int i=3;i>=1;--i) {
			bool bl=true;
			for(int k=i;k>=1;--k) {
				if(Map[k][j]) bl=false;
			}
			if(bl) continue;
			if(Map[i+1][j]==0) {
				for(int k=i;k>=1;--k) {
					Map[k+1][j]=Map[k][j];
				}
				Map[1][j]=0;
				++i;
			}
		}
		for(int i=3;i>=1;--i) {
			if(Map[i+1][j]==Map[i][j]) {
				Map[i+1][j]+=Map[i][j];
				sc+=Map[i+1][j];
				for(int k=i-1;k>=1;--k) {
					Map[k+1][j]=Map[k][j];
				}
				Map[1][j]=0;
			}
		}
	}
}
void move_left() {
	for(int i=1;i<=4;++i) {
		for(int j=2;j<=4;++j) {
			bool bl=true;
			for(int k=j;k<=4;++k) {
				if(Map[i][k]) bl=false;
			}
			if(bl) continue;
			if(Map[i][j-1]==0) {
				for(int k=j;k<=4;++k) {
					Map[i][k-1]=Map[i][k];
				}
				Map[i][4]=0;
				--j;
			}
		}
		for(int j=2;j<=4;++j) {
			if(Map[i][j-1]==Map[i][j]) {
				Map[i][j-1]+=Map[i][j];
				sc+=Map[i][j-1];
				for(int k=j+1;k<=4;++k) {
					Map[i][k-1]=Map[i][k];
				}
				Map[i][4]=0;
			}
		}
	}
}
void move_right() {
	for(int i=1;i<=4;++i) {
		for(int j=3;j>=1;--j) {
			bool bl=true;
			for(int k=j;k>=1;--k) {
				if(Map[i][k]) bl=false;
			}
			if(bl) continue;
			if(Map[i][j+1]==0) {
				for(int k=j;k>=1;--k) {
					Map[i][k+1]=Map[i][k];
				}
				Map[i][1]=0;
				++j;
			}
		}
		for(int j=3;j>=1;--j) {
			if(Map[i][j+1]==Map[i][j]) {
				Map[i][j+1]+=Map[i][j];
				sc+=Map[i][j+1];
				for(int k=j-1;k>=1;--k) {
					Map[i][k+1]=Map[i][k];
				}
				Map[i][1]=0;
			}
		}
	}
}
void getnew(int pos,int num) {
	while(Map[pos/4+1][pos%4+1]) {
		++pos;
		pos%=16;
	}
	Map[pos/4+1][pos%4+1]=num;
}
void readsave() {
	freopen("save","r",stdin);
	scanf("%lld%lld",&hsc,&sc);
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			scanf("%d",&Map[i][j]);
	fclose(stdin);
	freopen("CON","r",stdin);
}
void writesave() {
	freopen("save","w",stdout);
	printf("%lld %lld ",hsc,sc);
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			printf("%d ",Map[i][j]);
	fclose(stdout);
	freopen("CON","w",stdout);
}
void run() {
	srand(time(0));
	int pos=rand()%16;
	int num=4-(bool)(rand()%10)*2;
	getnew(pos,num);
	pos=rand()%16;
	num=4-(bool)(rand()%10)*2;
	getnew(pos,num);
	readsave();
	while(check_up()||check_down()||check_left()||check_right()) {
		HideCurSor();
		draw();write();SetPos2(40,5);printf("        score:%lld",sc);SetPos2(40,4);printf("highest score:%lld",hsc);
		for(int i=1;i<=4;++i) {
			for(int j=1;j<=4;++j) {
				if(Map[i][j]>=2048) {
					SetPos2(1,19);
					printf("             You Win!");
				}
			}
		}
		Sleep(150);
		while(1) {
			HideCurSor();
			if(KEY_DOWN(VK_ESCAPE))
				return;
			if(KEY_DOWN(VK_UP)&&check_up()) {
				move_up();
				break;
			}
			if(KEY_DOWN(VK_DOWN)&&check_down()) {
				move_down();
				break;
			}
			if(KEY_DOWN(VK_LEFT)&&check_left()) {
				move_left();
				break;
			}
			if(KEY_DOWN(VK_RIGHT)&&check_right()) {
				move_right();
				break;
			}
		}
		pos=rand()%16;
		num=4-(bool)(rand()%10)*2;
		getnew(pos,num);
		hsc=max(hsc,sc);
		writesave();
	}
	draw();write();SetPos2(40,5);printf("score:%lld",sc);
	SetPos2(1,19);
	printf("            GAME OVER!\n");
	printf("    Press Enter or Esc to exit");
	while(!KEY_DOWN(VK_RETURN)&&!KEY_DOWN(VK_ESCAPE)) HideCurSor();
	return;
}
int main() {
	run();
	return 0;
}
