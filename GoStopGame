#include"gostop.h"

Card card[DECK] = { {1,"1광",'G'},{1,"1홍단",'D'},{1,"1피1",'P'},{1,"1피2",'P'},
	{2,"2새",'A'},{2,"2홍단",'D'},{2,"2피1",'P'},{2,"2피2",'P'},
	{3,"3광",'G'},{3,"3홍단",'D'},{3,"3피1",'P'},{3,"3피2",'P'},
	{4,"4새",'A'},{4,"4초단",'D'},{4,"4피1",'P'},{4,"4피2",'P'},
	{5,"5열끗",'A'},{5,"5초단",'D'},{5,"5피1",'P'},{5,"5피2",'P'},
	{6,"6열끗",'A'},{6,"6청단",'D'},{6,"6피1",'P'},{6,"6피2",'P'},
	{7,"7열끗",'A'},{7,"7초단",'D'},{7,"7피1",'P'},{7,"7피2",'P'},
	{8,"8광",'G'},{8,"8새",'A'},{8,"8피1",'P'},{8,"8피2",'P'},
	{9,"9국진",'A'},{9,"9청단",'D'},{9,"9피1",'P'},{9,"9피2",'P'},
	{10,"10열끗",'A'},{10,"10청단",'D'},{10,"10피1",'P'},{10,"10피2",'P'},
	{11,"11광",'G'},{11,"11쌍피",'P'},{11,"11피1",'P'},{11,"11피2",'P'},
	{12,"12비광",'G'},{12,"12열끗",'A'},{12,"12띠",'D'},{12,"12쌍피",'P'} };

int main()
{
	Card Asave[7]={0},Bsave[7]={0},Csave[7]={0},A_Gsave[24]={0},B_Gsave[24]={0},C_Gsave[24]={0},_opensave[24]={0},_decksave[48]={0};
	//저장하고 로드할 시에 카드의 데이터들을 임시로 저장할 공간

	Node *a = NULL,*b = NULL,*c = NULL;
	Node *a_g = NULL,*b_g = NULL,*c_g = NULL;
	Node *open = NULL;
	Node *draw = NULL;

	List A, B, C; //플레이어 A,B,C를 나타낸다.
	List A_G, B_G, C_G; //플레이어 A,B,C가 각각 먹은 카드들이다.
	List _deck; //산패리스트(덱)에 대한 리스트이다.
	List _open; //현재 깔린 패들에 대한 리스트이다.

	List* A_G_Save = &A_G; //A가 얻은 카드리스트들의 시작주소를 담은 변수
	List* B_G_Save = &B_G; //B가 얻은 카드리스트들의 시작주소를 담은 변수
	List* C_G_Save = &C_G; //C가 얻은 카드리스트들의 시작주소를 담은 변수

	Score kind  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int temp[8] = {0}; //임의의 값을 저장하기 위한 배열
	int saveA=0,saveB=0,saveC=0; //로드한 횟수
	int nagari = 0,nagari_countA = 0,nagari_countB = 0,nagari_countC = 0; //나가리, //나가리 횟수
	int shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
	int goA = 0, goB = 0, goC = 0; //고 횟수 세기
    int scoreA = 0,scoreB = 0, scoreC = 0; //각 플레이어가 얻은 점수
	int moneyA = 100000, moneyB = 100000, moneyC = 100000; // 각 플레이어가 갖고있는 돈의 액수
	int nagari_arr[3] = {nagari_countA,nagari_countB,nagari_countC};
	int shake_arr[3] = {shakeA,shakeB,shakeC};
	int go_arr[3] = {goA,goB,goC};
	int score_arr[3] = {scoreA,scoreB,scoreC};
	int money_arr[3] = {moneyA,moneyB,moneyC};
	
	char choice,choiceA,choiceB,choiceC; //받은 명령을 변수에 받음.
	

	srand(time(NULL));  //매 게임 시작마다 주어진 카드의 종류를 다르게 한다.
	Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
	
	GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성

	chongtongA = ChongTong(&A); //A에 대한 총통을 계산해봄
	chongtongB = ChongTong(&B); //B에 대한 총통을 계산해봄
	chongtongC = ChongTong(&C); //C에 대한 총통을 계산해봄


	while(1)
{
Ago: //A에 대한 잘못된 명령을 다시 수행하기 위해 넣은 레이블
	
   if((nagari = Nagari(&A,&_deck,scoreA,scoreB,scoreC)) == -1){//나가리가 나면 다음 판엔 점수가 2배이다 
	      nagari_countA++;
			break;
   }
		printf("*");
		PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open); //현재 깔린 패 화면 출력
		Display_DeckCard(&_deck);
		
		if(chongtongA == 4){
			printf("A가 총통이 났습니다\n");
			break;
		}

		else if(chongtongB == 4){
			printf("B가 총통이 났습니다.\n");
			break;
		}

		else if(chongtongC == 4){
			printf("C가 총통이 났습니다.\n");
			break;
		}

		
	CHOICEA: //A차례에서 수행할 명령
		choiceA = Command();

	
	

        if(choiceA == 'e'){
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck); //e키를 누르면 종료된다
			return 0;
		}
		else if(choiceA == 'h'){ //h키를 누르면 단축키에 대한 설명이 나온다
			Display_Help();
			goto Ago;
		}
		else if(choiceA == 'b'){ //b키를 누르면 잔고가 나온다 
			Display_Money(moneyA,moneyB,moneyC);
			goto Ago;
		}

		else if(choiceA == 'v'){ //v키를 누르면 저장을 한다
			saveA=Save(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,temp);
			goto CHOICEA;
		}

		else if(choiceA == 'l'){ //l키를 누르면 저장한 파일을 로드한다 
			Load(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,saveA,saveB,saveC,temp);
			if(saveB == 1) //만약 B턴에서 저장했으면 그 데이터를 불러온다 
				goto CHOICEB;

			else if(saveC == 1) //만약 C턴에서 저장했으면 그 데이터를 불러온다 
				goto CHOICEC;
				
			saveB=0,saveC=0;
			
		}

		if((shakeA = Shake(&A)) == 3) //만약 같은 패가 3장있으면 흔들기를 시전한다 
			printf("흔들기를 시전하였습니다.\n");
		
			a = Search_And_PayPlayerCard(&A,choiceA); //A의 패에서 카드 한장을 고르고 그것을 낸다 

			
			
			if(a == NULL){
				
				printf("없는 카드 이거나 잘못된 명령입니다.\n"); //명령을 잘못 입력하거나 패에 없는 카드를 고르면 발동한다.
				goto CHOICEA;
				

				
			}

			else{
				draw = Draw_From_Deck(&_deck); //덱에서도 카드 한장을 뽑는다
				Search_And_TakeOpenCard(A_G_Save,B_G_Save,C_G_Save,&_open,a,draw); //그리고 덱과 낸 카드를 먹은 패 리스트에 추가한다.
				scoreA = Score_Calculate(&A_G,&B_G,&C_G,&kind); //그리고 먹은 리스트들의 카드들에 따라 점수를 계산한다
	            }
			
			if(scoreA >= 3){ //3점 이상이 나면 
				system("clear");
				printf("*");
		PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open); //현재 깔린 패 화면 출력
		Display_DeckCard(&_deck);
				
			printf("고 or 스톱? (g or s):"); //고와 스톱중 하나를 정한다 
			scanf("%c",&choice);
	     fpurge(stdin); //버퍼를 비워주는 역할을 한다
			
			if(choice == 'g'){ //만약 고를 외치면 
			goA++; //고 횟수를 증가시킨다 
			printf("%d고\n",goA);
			}

			else 
			break; //스톱이면 게임을 멈춘다 
		   }
			
			
		
			
		
		system("clear");



Bgo: //B에 대한 잘못된 명령을 다시 수행하기 위해 넣은 레이블
	
		
		if((nagari = Nagari(&B,&_deck,scoreA,scoreB,scoreC)) == -1){//나가리가 나면 다음 판엔 점수가 2배이다 
			nagari_countB++;
			break;
		}
		
		PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		printf("*");
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open); //현재 깔린 패 화면 출력
		Display_DeckCard(&_deck);
		
		if(chongtongA == 4){ //총통이 나면 10점을 얻고 게임에서 이긴다 
			printf("A가 총통이 났습니다\n");
			break;
		}

		else if(chongtongB == 4){
			printf("B가 총통이 났습니다.\n");
			break;
		}

		else if(chongtongC == 4){
			printf("C가 총통이 났습니다.\n");
		    break;
		}
		
		
		
	CHOICEB://B차례에서 수행할 명령
        choiceB = Command();
		if(choiceB == 'e'){ //종료하기 
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			return 0;
		}
		else if(choiceB == 'h'){ //도움말 보기 
			Display_Help();
			goto Bgo;
		}

		else if(choiceB == 'b'){ //잔고 보기 
			Display_Money(moneyA,moneyB,moneyC);
			goto Bgo;
		}

		else if(choiceB == 'v'){ //저장하기 
			saveB = Save(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,temp);
			goto CHOICEB;
		}

		else if(choiceB == 'l'){ //로드하기 
			Load(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,saveA,saveB,saveC,temp);
		    if(saveA == 1) //A턴 에서 저장한 데이터를 부른다 
				goto CHOICEA;

			else if(saveC == 1) //C턴에서 저장한 데이터를 부른다 
				goto CHOICEC;
			
			saveA=0,saveC=0;
		}

		if((shakeB = Shake(&B)) == 3) //같은 월의 카드가 3장있으면 흔들기를 한다.
			printf("흔들기를 시전하였습니다.\n");
		
			b = Search_And_PayPlayerCard(&B,choiceB); //패에서 카드 한장을 골라 낸다 

			
           
			if(b == NULL){ //없는 카드거나 잘못된 키를 누르면 발동한다 
				
				printf("없는 카드 이거나 잘못된 명령입니다.\n");
				goto CHOICEB;
				
				
			}

			else{
				draw = Draw_From_Deck(&_deck); //덱에서 카드를 드로우한다 
				Search_And_TakeOpenCard(B_G_Save,A_G_Save,C_G_Save,&_open,b,draw); //낸 후에 깔린 패 리스트에서 하나 가져간다 
				scoreB = Score_Calculate(&B_G,&A_G,&C_G,&kind); //현재 먹은 패 리스트에있는 카드들의 종류에따라 점수를 계산한다.
	            }
			
			if(scoreB >= 3){
				system("clear");
				PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		printf("*");
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open); //현재 깔린 패 화면 출력
		Display_DeckCard(&_deck);
				printf("고 or 스톱? (g or s):");
			scanf("%c",&choice);
	       fpurge(stdin); //버퍼를 비워주는 역할을 한다
			
			if(choice == 'g'){ //고를 누르면 
			goB++; //고 횟수가 증가하고 
			printf("%d고\n",goB); 
			}

			else 
			break; //다른 경우에는 게임을 중단한다.
		}
			
			
		

		
		system("clear");





Cgo: //C에 대한 잘못된 명령을 다시 수행하기 위해 넣은 레이블
	
		if((nagari = Nagari(&C,&_deck,scoreA,scoreB,scoreC)) == -1){ //나가리가 나면 다음 판엔 점수가 2배이다 
			nagari_countC++;
			break;
		}
		PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		printf("*");
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open);
		Display_DeckCard(&_deck);

		if(chongtongA == 4){ //총통이 나면 10점을 얻고 게임을 이기게 된다.
			printf("A가 총통이 났습니다\n");
			break;
		}

		else if(chongtongB == 4){
			printf("B가 총통이 났습니다.\n");
			break;
		}

		else if(chongtongC == 4){
			printf("C가 총통이 났습니다.\n");
			break;
		}
		
	CHOICEC: //C차례에서 수행할 명령
		choiceC = Command();
		
		if(choiceC == 'e'){ //e키는 종료 
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			return 0;
		}
		else if(choiceC == 'h'){ //도움말 
			Display_Help();
			goto Cgo;
		}

		else if(choiceC == 'b'){ //잔고 확인 
			Display_Money(moneyA,moneyB,moneyC);
			system("clear");
			goto Cgo;
		}

		
        else if(choiceC == 'v'){ //저장하기 
			saveC=Save(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,temp);
			goto CHOICEC;
		}

		else if(choiceC == 'l'){ //로드하기 
			Load(Asave,Bsave,Csave,A_Gsave,B_Gsave,C_Gsave,_opensave,_decksave,&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck,nagari_arr,shake_arr,go_arr,score_arr,money_arr,saveA,saveB,saveC,temp);
		if(saveA == 1)
				goto CHOICEA;    //A턴에서 저장했으면 그 데이터를 불러온다 
		
		else if(saveB == 1)
				goto CHOICEB;  //B턴에서 저장했으면 그 데이터를 불러온다.

		saveA=0,saveB=0;
		}

		if((shakeC = Shake(&C)) == 3) //패에 같은 달이 3장있으면 흔들기를 시전한다 
			printf("흔들기를 시전하였습니다.\n");
		

			c = Search_And_PayPlayerCard(&C,choiceC); //패에서 카드 한장을 골라 낸다 

			
			
            if(c == NULL){ //없는 카드이거나 잘못된 키를 누르면 발동한다.
				
				printf("없는 카드 이거나 잘못된 명령입니다.\n");
				goto CHOICEC;
				

				
			}
			else{
				draw = Draw_From_Deck(&_deck); //카드 한장을 뽑는다 
				Search_And_TakeOpenCard(C_G_Save,A_G_Save,B_G_Save,&_open,c,draw);//깔린패 리스트에서 가져간다 
				scoreC = Score_Calculate(&C_G,&A_G,&B_G,&kind);//먹은 패 리스트에 있는 카드들의 종류에 따라 점수를 계산한다.
	          }
			
			
			if(scoreC >= 3){
				system("clear");
				PlayerA(&A,A_G_Save);
		Display_Score(scoreA); //A의 점수
		PlayerB(&B,B_G_Save);
		Display_Score(scoreB); //B의 점수
		printf("*");
		PlayerC(&C,C_G_Save);
		Display_Score(scoreC); //C의 점수
		Display_OpenCard(&_open);
		Display_DeckCard(&_deck);
			printf("고 or 스톱? (g or s):"); //고나 스톱을 외친다 
			scanf("%c",&choice);
	       fpurge(stdin);
			
			if(choice == 'g'){ //고이면 
			goC++; //고 횟수를 늘리고 
			printf("%d고\n",goC); 
			}

			else 
			break; //그렇지 않은 경우면 종료한다 
		}

			
			
	system("clear");


}

   if(chongtongA == 4)
	   scoreA += 10; //총통일시에 10점으로 계산 

   else if(chongtongB == 4)
	   scoreB += 10; //총통일시에 10점으로 계산

   else if(chongtongC == 4)
	   scoreC += 10; //총통일시에 10점으로 계산

   else if(nagari == -1){
	   scoreA = scoreA; //나가리일 경우 박 계산을 하지 않음
       scoreB = scoreB; //나가리일 경우 박 계산을 하지 않음
	   scoreC = scoreC; //나가리일 경우 박 계산을 하지 않음
   }

   else{                                                                             // 그이외의 경우에는 
    scoreA = Bak_Calculate(&B_G,&C_G,scoreA,goA,goB,goC,shakeA,nagari_countA,&kind); //박 계산까지 하여 점수를 낸다
	scoreB = Bak_Calculate(&A_G,&C_G,scoreB,goB,goA,goC,shakeB,nagari_countB,&kind); //박 계산까지 하여 점수를 낸다
	scoreC = Bak_Calculate(&A_G,&B_G,scoreC,goC,goA,goB,shakeC,nagari_countC,&kind); //박 계산까지 하여 점수를 낸다
   }
	
	printf("\n총 결과\nA : %d점\nB : %d점\nC : %d점\n\n",scoreA,scoreB,scoreC);
	
	if(scoreA >= WIN && nagari != -1){  //A가 이겼을때
		printf("A의 승리입니다.\n");
	moneyA = Money_Calculate_Get(scoreA,moneyA); //점수의 100배만큼 돈을 얻는다 
	moneyB = Money_Calculate_Minus(scoreA,moneyB); //나머지 플레이어들은 A의 점수의 100배만큼 돈을 잃는다.
	moneyC = Money_Calculate_Minus2(scoreA,moneyC);
	}

	else if(scoreB >= WIN && nagari != -1){ //B가 이겼을때
		printf("B의 승리입니다.\n");
	moneyB = Money_Calculate_Get(scoreB,moneyB); //점수의 100배만큼 돈을 얻는다
	moneyA = Money_Calculate_Minus(scoreB,moneyA); //나머지 플레이어들은 A의 점수의 100배만큼 돈을 잃는다.
	moneyC = Money_Calculate_Minus2(scoreB,moneyC);
	}

	else if(scoreC >= WIN && nagari != -1){ //C가 이겼을때
		printf("C의 승리입니다.\n");
	moneyC = Money_Calculate_Get(scoreC,moneyC); //점수의 100배만큼 돈을 얻는다
	moneyA = Money_Calculate_Minus(scoreC,moneyA); //나머지 플레이어들은 A의 점수의 100배만큼 돈을 잃는다.
	moneyB = Money_Calculate_Minus2(scoreC,moneyB);
	}

	printf("한번 더 하시겠습니까?(y or n) ");
	scanf("%c",&choice);
	fpurge(stdin); //버퍼를 비워주는 역할을 한다
	if(choice == 'y'){
		if(scoreA >= scoreB && scoreA >= scoreC){
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
            goto Ago;
		}
		
		else if(scoreB >= scoreA && scoreB >= scoreC){
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
			goto Bgo;
		}
		
		else if(scoreC >= scoreA && scoreC >= scoreA){
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
		    goto Cgo;
		}

		else if(nagari_countA >= 1){
			nagari = 0;
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
			goto Ago;
		    }

		else if(nagari_countB >= 1){
			nagari = 0;
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
			goto Bgo;
		    }

		else if(nagari_countC >= 1){
			nagari = 0;
			scoreA = 0,scoreB = 0,scoreC = 0;//각 플레이어가 얻은 점수
			goA = 0, goB = 0, goC = 0; //고 횟수 세기
			shakeA = 0,shakeB = 0, shakeC = 0, chongtongA = 0,chongtongB = 0,chongtongC = 0; //흔들기와 총통 횟수
			system("clear");
			Destroy_All(&A,&B,&C,&A_G,&B_G,&C_G,&_open,&_deck);
			Create_All_Lists(&A,&B,&C,&A_G,&B_G,&C_G,&_deck,&_open); //모든 리스트들을 생성함
			GameReady(card,&_deck,&_open,&A,&B,&C); //게임을 준비하기 위해 모든 리스트들을 생성
			goto Cgo;
		    }
			
	}

	
	 
	return 0;
}
/* 모든 리스트들을 생성하기 위함*/
void Create_All_Lists(List* A,List* B,List* C,List* A_G,List* B_G,List* C_G,List* _deck,List* _open)
{
	// A,B,C는 각 플레이어가 가지고 있는 패, A_G,B_G,C_G리스트들은 먹은 패, _open은 깔린패, _deck은 산패리스트(덱)이다
	A -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	B -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	C -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	A_G -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	B_G -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	C_G -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	_deck -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.
	_open -> head = (Node*)calloc(1,sizeof(Node)); //헤드 노드에 대한 메모리를 할당한다.

	A -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	B -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	C -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	A_G -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	B_G -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	C_G -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	_deck -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.
	_open -> tail = (Node*)calloc(1,sizeof(Node)); //테일 노드에 대한 메모리를 할당한다.

/* 헤드 노드와 테일노드 사이의 링크 연결하기 */
	A -> head -> prev = A -> head; // 헤드의 prev는 자신을 가리키고
	A -> tail -> next = A -> tail; // 테일의 next는 자신을 가리키고
	A -> head -> next = A -> tail; // 헤드의 next는 테일을 가리키고 
	A -> tail -> prev = A -> head; // 테일의 prev는 헤드를 가리킨다 

	B -> head -> prev = B -> head; // 헤드의 prev는 자신을 가리키고
	B -> tail -> next = B -> tail; // 테일의 next는 자신을 가리키고
	B -> head -> next = B -> tail; // 헤드의 next는 테일을 가리키고 
	B -> tail -> prev = B -> head;  // 테일의 prev는 헤드를 가리킨다 

	C -> head -> prev = C -> head;// 헤드의 prev는 자신을 가리키고
	C -> tail -> next = C -> tail; // 테일의 next는 자신을 가리키고
	C -> head -> next = C -> tail; // 헤드의 next는 테일을 가리키고 
	C -> tail -> prev = C -> head; // 테일의 prev는 헤드를 가리킨다 

	A_G -> head -> prev = A_G -> head; // 헤드의 prev는 자신을 가리키고
	A_G -> tail -> next = A_G -> tail; // 테일의 next는 자신을 가리키고
	A_G -> head -> next = A_G -> tail; // 헤드의 next는 테일을 가리키고 
	A_G -> tail -> prev = A_G -> head; // 테일의 prev는 헤드를 가리킨다 

	B_G -> head -> prev = B_G -> head; // 헤드의 prev는 자신을 가리키고
	B_G -> tail -> next = B_G -> tail; // 테일의 next는 자신을 가리키고
	B_G -> head -> next = B_G -> tail; // 헤드의 next는 테일을 가리키고 
	B_G -> tail -> prev = B_G -> head; // 테일의 prev는 헤드를 가리킨다 

	C_G -> head -> prev = C_G -> head; // 헤드의 prev는 자신을 가리키고
	C_G -> tail -> next = C_G -> tail; // 테일의 next는 자신을 가리키고 
	C_G -> head -> next = C_G -> tail; // 헤드의 next는 테일을 가리키고 
	C_G -> tail -> prev = C_G -> head; // 테일의 prev는 헤드를 가리킨다 

	_deck -> head -> prev = _deck -> head; // 헤드의 prev는 자신을 가리키고
	_deck -> tail -> next = _deck -> tail; // 테일의 next는 자신을 가리키고
	_deck -> head -> next = _deck -> tail; // 헤드의 next는 테일을 가리키고 
	_deck -> tail -> prev = _deck -> head; // 테일의 prev는 헤드를 가리킨다 

	_open -> head -> prev = _open -> head; // 헤드의 prev는 자신을 가리키고
	_open -> tail -> next = _open -> tail; // 테일의 next는 자신을 가리키고
	_open -> head -> next = _open -> tail; // 헤드의 next는 테일을 가리키고 
	_open -> tail -> prev = _open -> head; // 테일의 prev는 헤드를 가리킨다 

/* curr노드는 새 노드를 생성하기위한 임시저장 공간 노드이다.*/
	A -> curr = NULL;
	B -> curr = NULL;
	C -> curr = NULL;

	A_G -> curr = NULL;
	B_G -> curr = NULL;
	C_G -> curr = NULL;

	_open -> curr = NULL;
	_deck -> curr = NULL;
}
//각 리스트들을 다루기위해 각 리스트에 대한 메모리들을 모두 할당시킨다.

void Create(List* lp,int count) //count 수만 큼 헤드와 테일 노드 사이에 리스트를 생성
{
	int i = 0;
	for(i=0;i<count;++i){ 
		lp -> curr = (Node*)calloc(1,sizeof(Node)); // curr노드에 메모리를 하나 할당하고 
		lp -> curr -> prev = lp -> head; // curr의  prev에 헤드를 연결하고 
		lp -> curr -> next = lp -> head -> next; //curr의 next에 그다음 노들들 연결하고 
		lp -> head -> next -> prev = lp -> curr; //curr next의 노드는 curr을 연결하고 
		lp -> head -> next = lp -> curr; //헤드의 다음 노드는 curr로 연결한다 
		lp -> curr = NULL; 
	}
}

void GameReady(Card* card,List* _deck,List* _open,List* A,List* B,List* C){
    SetDeck(card,_deck); //카드를 섞음
	Open_Field(_deck,_open); //그리고 산패에서 카드를 꺼내서 6장을 깐다

	HavingCard(A,_deck); //A가 7장 패를 쥔다.
	HavingCard(B,_deck); //B가 7장 패를 쥔다.
	HavingCard(C,_deck); //C가 7장 패를 쥔다.
}

void SetDeck(Card* card, List* _deck){ //카드를 하나씩 쌓아 올려서 덱을 생성한다.
	int i;
	/* 카드 배열을 섞음 */
	for(i = 0; i < DECK; i++){
		int put = rand() % 48; //48장의 카드를 
		Card tmp = card[i]; //tmp라는 임시 공간에 하나씩 집어 넣으면서 
		card[i] = card[put];
		card[put] = tmp; //카드를 섞는다 
	}

	/* 리스트 노드에 카드 배열의 값을 대입 */
	for(i = 0; i < DECK; i++){
		_deck = Deck_AddNode(_deck,card[i]); //덱 쌓아올리는 함수 호출
	}
}

List* Deck_AddNode(List* _deck,Card card) //카드를 차례로 하나씩 쌓아올린다.
{
	_deck -> curr = (Node*)calloc(1,sizeof(Node));

	_deck -> curr -> prev = _deck -> head; // curr노드에 메모리를 하나 할당하고 
	_deck -> curr -> next = _deck -> head -> next; // curr의  prev에 헤드를 연결하고 
	_deck -> head -> next -> prev = _deck -> curr; //curr -> next의 노드는 curr을 연결하고 
	_deck -> head -> next = _deck -> curr; //헤드의 다음 노드는 curr로 연결한다 
	//헤드 노드를 시작으로 하나씩 쌓아올린다.
	_deck -> curr -> data = card;

	return _deck;
}

void Open_Field(List* _deck,List* _open) //필드 위에 카드를 6장 깔아 놓는다.
{
	int i;
	Card data;
	for(i=0;i<6;++i)
	{
		_deck -> curr = _deck -> head -> next; //헤드 다음 노드의 주소를 _deck -> curr에 넣는다.
		data = _deck -> curr -> data; // data란 변수에 덱에 있던 카드 정보를 넣는다.
		_deck -> head -> next = _deck -> curr -> next; // 링크를 끊는다.
		_deck -> curr -> next -> prev = _deck -> head; // 링크를 끊는다.
		free(_deck -> curr); //그 리스트를 삭제한다
		_deck -> curr = NULL;

		_open -> curr = (Node*)calloc(1,sizeof(Node)); //오픈 리스트에서 새로운 노드 하나를 생성한다
		_open -> curr -> prev = _open -> head;   // curr의  prev에 헤드를 연결하고 
		_open -> curr -> next = _open -> head -> next;  //curr -> next의 노드는 curr을 연결하고 
		_open -> head -> next -> prev = _open -> curr;  //curr 다음노드는 curr을 연결 
		_open -> head -> next = _open -> curr; // 헤드의 next에 curr 연결 
		// 그리고 전 노드와 후 노드와 연결시킨다.
		_open -> curr -> data = data; //새로 만든 노드 데이터에 카드 정보를 넣는다.
	}

}

void HavingCard(List* player,List* _deck) //플레이어마다 각각 7장씩 카드를 가진다
{
	int i;
	Card data;
	for(i=0;i<7;++i)
	{
		_deck -> curr = _deck -> head -> next; //헤드 다음의 노드의 주소를 _deck -> curr에 넣는다
		data = _deck -> curr -> data; //curr에 있는 카드 정보를 임의의 data 변수에 넣는다.
		_deck -> head -> next = _deck -> curr -> next; //링크를 끊는다
		_deck -> curr -> next -> prev = _deck -> head; //링크를 끊는다
		free(_deck -> curr);
		_deck -> curr = NULL;
		// 그 뒤에 _deck 노드 하나를 삭제한다

		player -> curr = (Node*)calloc(1,sizeof(Node)); //player 리스트에서 새로운 노드 하나를 생성한다.
		player -> curr -> prev = player -> head; // curr의  prev에 헤드를 연결하고 
		player -> curr -> next = player -> head -> next; //curr -> next의 노드는 curr을 연결하고 
		player -> head -> next -> prev = player -> curr;  //curr 다음노드는 curr을 연결 
		player -> head -> next = player -> curr; //헤드의 next에 curr 연결 
		// 그리고 생성한 노드의 전과 후를 연결한다.

		player -> curr -> data = data; //그리고 임시로 저장했던 카드 정보를 player리스트의 data에 넣는다.
	}
}

int GetListNum(List* list){
	/* 리스트의 개수 리턴 */
	int count = 0;
	list -> curr = list -> head -> next;
	while(list -> curr != list -> tail){
		count ++;
		list -> curr = list -> curr -> next;
	}
	return count;
}


//각각 플레이어들이 들고 있는 패들의 정보를 보여준다
void Display_Player(List* player)
{
	player -> curr = player -> head -> next;
	while(player -> curr != player -> tail)
	{
		printf(" %s ",player -> curr -> data.cardname);
		player -> curr = player -> curr -> next;
	}
	printf("\n");
} 
// 현재 깔린 패에 대한 정보를 보여 준다
void Display_OpenCard(List* _open)
{
	int count = 1;
	_open -> curr = _open -> head -> next; 
	printf("깔린 패 : ");
	while(_open -> curr != _open -> tail)
	{
		printf(" %s ",_open -> curr -> data.cardname);
		if(count%6==0)
			printf("\n");
		++count;
		_open -> curr = _open -> curr -> next;
	}
	printf("\n\n");

} 
//현재 각 플레이어가 먹은 패들의 정보를 보여준다
void Display_SaveCard(List* p_g)
{
	p_g -> curr = p_g -> head -> next;
	printf("먹은 패 : ");
	while(p_g -> curr != p_g -> tail)
	{
		printf(" %s ",p_g -> curr -> data.cardname);
		p_g -> curr = p_g -> curr -> next;
	}
	printf("\n");
} 

Node* Draw_From_Deck(List* _deck) //덱에서 카드 한장을 드로우 한다.
{

	_deck -> curr = _deck -> head -> next; //_deck -> curr에 헤드 다음의 시작주소를 가리키게 한다

	_deck -> head -> next = _deck -> curr -> next; //링크를 끊는다.
	_deck -> curr -> next -> prev = _deck -> head; //링크를 끊는다

	return _deck -> curr; //그리고 드로우한 카드 정보를 리턴한다.
} 

Node* Search_And_PayPlayerCard(List* player,char choice)
{
	Node* node;
	int count = 1; //count수를 1로 초기화한다
	player -> curr = player -> head -> next;
	while(player -> curr != player -> tail) //테일 노드가 나오기 전까지 반복문을 돌린다
	{
		if(count == (choice - '0')){  //만약 choice의 수와 count의 수가 같으면
			node = player -> curr;
			node -> prev -> next = node -> next; //링크를 끊는다.
			node -> next -> prev = node -> prev; // 링크를 끊는다.
			return node; //저장한 데이터를 리턴한다.
		}
		else
			player -> curr = player -> curr -> next; //그렇지 않으면 그 다음 노드로 이동한다.

		count++; //count수는 하나 증가 시킨다
	}

	return NULL;
}

void Search_And_TakeOpenCard(List* taker,List* p1,List* p2,List* _open, Node* data_pay, Node* data_draw)
  {
  Card temp;
  int choice, i; //1번과 2번중 선택
  char* cardname[3] = {NULL};
  int pay_count=0;  //한번 카드를 냈을때 마다 횟수를 더한다.
  int draw_count=0; //한번 드로우 할때마다 횟수를 더한다.
  int pay_data_count=0; //낸 카드를 기준으로 깔린패에서같은 달의 카드를 찾을때 마다 횟수를 더한다.
  int draw_data_count=0; //드로우한 카드를 기준으로 깔린패에서 같은 달의 카드를 찾을때 마다 횟수를 더한다.
  unsigned pay_save; // 냈던 카드의 월을 저장 한다
  unsigned draw_save; //뽑았던 카드의 월을 저장 한다.
  
  _open -> curr = data_pay; //낸 카드의 패를 _open -> curr에 임시로 저장
  _open -> curr -> prev = _open -> head; //링크연결
  _open -> curr -> next = _open -> head -> next; //링크연결
  _open -> head -> next -> prev = _open -> curr; //링크연결
  _open -> head -> next = _open -> curr; //링크연결
  pay_count++;
  pay_save = data_pay -> data.month; //지불한 카드의 정보를 저장한다 

  while(_open -> curr != _open -> tail)
  {
  	if(_open -> curr -> next -> data.month == pay_save){
  		pay_data_count++;
  		_open -> curr = _open -> curr -> next;
  	}
     
     else
  	_open -> curr = _open -> curr -> next;
  }
  _open -> curr = NULL;

  _open -> curr = data_draw; //덱에서 뽑은 카드의 패를 _open -> curr에 임시로 저장
  _open -> curr -> prev = _open -> head; //링크 연결
  _open -> curr -> next = _open -> head -> next; //링크 연결
  _open -> head -> next -> prev = _open -> curr; //링크 연결
  _open -> head -> next = _open -> curr; //링크 연결
  draw_count++;

  draw_save = data_draw -> data.month; //덱에서 뽑은 카드의 정보를 저장한다.
  
  while(_open -> curr != _open -> tail)
  {
  	if(_open -> curr -> next -> data.month == draw_save){
  		draw_data_count++;
  		_open -> curr = _open -> curr -> next;
  	}

  	else
  		_open -> curr = _open -> curr -> next;
  }
  _open -> curr = NULL;

  
  /* 가져가는 방식*/
  if (draw_count == 1 && draw_data_count == 0 && pay_count == 1 && pay_data_count == 1 ) //패 2장 먹기(낸 카드를 중심으로)
	  {
		  _open -> curr = _open -> head -> next;
		   while(_open -> curr != _open -> tail){ //
		  if(_open -> curr -> data.month == data_pay -> data.month){
			 _open -> curr -> prev -> next = _open -> curr -> next;
             _open -> curr -> next -> prev = _open -> curr -> prev;

			        temp = _open -> curr -> data;
					_open -> curr = _open -> head -> next;
					_open -> curr -> data.month = 0;				
					
					

			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
            	    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;

					
                   }
		  else
                _open -> curr = _open -> curr -> next;
		 
		   }  
		   taker -> curr = NULL;
           _open -> curr = NULL;
	  }
	  
	 
	  
	  else if(draw_count == 1 && draw_data_count == 1 && pay_count == 1 && pay_data_count == 0) //따닥
	  {
		  _open -> curr = _open -> head -> next;
		  while(_open -> curr != _open -> tail){
		  if(_open -> curr -> data.month == data_draw -> data.month){
			 _open -> curr -> prev -> next = _open -> curr -> next;
             _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					
					
				    
			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;

				

					
		  }
		  else
			  _open -> curr = _open -> curr -> next;
		  }
	 taker -> curr = NULL;
      _open -> curr = NULL;
	  }
	 
  	 
	  else if(draw_count == 1 && draw_data_count == 2 && pay_count == 1 && pay_data_count == 1 ) //설사 
  	 {   
		 printf("저런 쌌습니다..\n");
  		  ;
  	 }

  	else if(draw_count == 1 && draw_data_count == 0 && pay_count == 1 && pay_data_count == 2 ) //둘 중 하나 고르기 (낸 카드의 월을 기준으로)
	{
		i=0;
		_open -> curr = _open -> head -> next;
		while(_open -> curr != _open -> tail){
		   if(_open -> curr -> data.month == data_pay -> data.month){
			   printf(" %s(%d) ",cardname[i] = _open -> curr -> data.cardname,i);
			   ++i;

			   
			   _open -> curr = _open -> curr -> next;
		   
		  }
		   else
			   _open -> curr = _open -> curr -> next;
		}
		_open -> curr = NULL;
		printf("\n어떤 카드를 고르시겠습니까((0,1) or (0,2))");
		scanf("%d",&choice);
		fpurge(stdin); //버퍼를 비워주는 역할을 한다
		if(choice == 1)
		{
			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.month == data_pay -> data.month){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }

			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){ 
				if(_open -> curr -> data.cardname == cardname[1]){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }
         }

		else if(choice != 1)
		{
			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.month == data_pay -> data.month){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }

			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.cardname == cardname[2]){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }
         }
	  }
  	
	else if(draw_count == 1 && draw_data_count == 0 && pay_count == 1 && pay_data_count == 3 ) //4장 다 가져가기 (낸 카드의 월을 기준으로)
            {
				_open -> curr = _open -> head -> next;
				while(_open -> curr != _open -> tail){
            	if(data_pay -> data.month == _open -> curr -> data.month){
            		_open -> curr -> prev -> next = _open -> curr -> next;
            	    _open -> curr -> next -> prev = _open -> curr -> prev;

                    temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
					
				    
			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
            	    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;

					

					
                   }
				else
					_open -> curr = _open -> curr -> next;
				}
				taker -> curr = NULL;
               _open -> curr = NULL;
            }
	
  	else if( draw_count == 1  && draw_data_count == 2 && pay_count == 1 && pay_data_count == 0)//둘 중 하나 고르기(드로우한 카드의 월을 기준으로)
           {
			   i=0;
		_open -> curr = _open -> head -> next;
		while(_open -> curr != _open -> tail){
		   if(_open -> curr -> data.month == data_draw -> data.month){
			   printf(" %s (%d) ",cardname[i] = _open -> curr -> data.cardname,i);
			   ++i;
			   
			   _open -> curr = _open -> curr -> next;

			  }
		   else
			   _open -> curr = _open -> curr -> next;
		}
		_open -> curr = NULL;
		printf("\n어떤 카드를 고르시겠습니까((0,1) or (0,2))");
		scanf("%d",&choice);
		fpurge(stdin); //버퍼를 비워주는 역할을 한다
		if(choice == 1)
		{
			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.month == data_draw -> data.month){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }

			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.cardname == cardname[1]){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }
         }

		else if(choice != 1)
		{
			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.month == data_draw -> data.month){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }

			_open -> curr = _open -> head -> next;
			while(_open -> curr != _open -> tail){
				if(_open -> curr -> data.cardname == cardname[2]){
					_open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

			       temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
				  
					taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
                    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
					break;
                }

				else
					_open -> curr = _open -> curr -> next;
		    }
         }
	  }
  	
	else if(draw_count == 1 && draw_data_count == 0 && pay_count == 1 && pay_data_count == 3 ) //4장 다 가져가기 (낸 카드의 월을 기준으로)
            {
				_open -> curr = _open -> head -> next;
				while(_open -> curr != _open -> tail){
            	if(data_pay -> data.month == _open -> curr -> data.month){
            		_open -> curr -> prev -> next = _open -> curr -> next;
            	    _open -> curr -> next -> prev = _open -> curr -> prev;

                    temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
					
				    
			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
            	    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;
				}
				else
					_open -> curr = _open -> curr -> next;
				}
				taker -> curr = NULL;
               _open -> curr = NULL;
            }
  	
	else if(draw_count == 1 && draw_data_count == 3 && pay_count == 1 &&  pay_data_count == 0 )//4장 다 가져가기(드로우한 카드의 월을 기준으로)
          {
			  _open -> curr = _open -> head -> next;
			  while(_open -> curr != _open -> tail){
            	if(data_draw -> data.month == _open -> curr -> data.month){
            		_open -> curr -> prev -> next = _open -> curr -> next;
            	    _open -> curr -> next -> prev = _open -> curr -> prev;
                   
					temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
					
				    
			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
            	    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;

					

					
                   }
				else
					_open -> curr = _open -> curr -> next;
			  }
			  taker -> curr = NULL;
              _open -> curr = NULL;
            }
	
  	else if(draw_count == 1  && draw_data_count == 1 && pay_count == 1 && pay_data_count == 1) //낸 카드의 월 2장, 드로우한 카드의 월 2장 
      {
		  _open -> curr = _open -> head -> next;
     while(_open -> curr != _open -> tail){
     if( _open -> curr -> data.month == data_pay-> data.month || _open -> curr -> data.month == data_draw -> data.month)
          {
			     _open -> curr -> prev -> next = _open -> curr -> next;
                _open -> curr -> next -> prev = _open -> curr -> prev;

                   temp = _open -> curr -> data;
				   free(_open -> curr);
				   _open -> curr = NULL;
				   _open -> curr = _open -> head -> next;
					
				    
			        taker -> curr = (Node*)calloc(1,sizeof(Node));
					taker -> curr -> data = temp;
            	    taker -> curr -> prev = taker -> head;
            	    taker -> curr -> next = taker -> head -> next;
            	    taker -> head -> next -> prev = taker -> curr;
            	    taker -> head -> next = taker -> curr;

					

					
	       }
	           else
               _open -> curr = _open -> curr -> next;
	     }
	       taker -> curr = NULL;
           _open -> curr = NULL;

            }
	
  	
	                                 
	
	


         if(draw_count == 1 && draw_data_count == 0 && pay_count == 1 && pay_data_count == 3 ) //4장 다 가져가기 (낸 카드의 월을 기준으로)
         	      taker = StealPee(taker,p1,p2); //피 뺏기
         
         if(draw_count == 1 && draw_data_count == 3 && pay_count == 1 &&  pay_data_count == 0 )//4장 다 가져가기(드로우한 카드의 월을 기준으로)
                  taker = StealPee(taker,p1,p2); //피 뺏기

		 if(draw_count == 1 && draw_data_count == 1 && pay_count == 1 && pay_data_count == 0)//따닥
                  taker = StealPee(taker,p1,p2); //피 뺏기
		 
		 if(_open -> head -> next == _open -> tail) //판쓰리
			      taker = StealPee(taker,p1,p2); //피 뺏기

		

 }



//플레이어 A에 대한 명령 입력
void PlayerA(List* A,List* A_G)
{
	printf("A   ");
	Display_Player(A); //A의 화면 출력
	Display_SaveCard(A_G); //A의 먹은 패 화면 출력
}
//플레이어 B에 대한 명령 입력
void PlayerB(List* B,List* B_G)
{
	printf("B  ");
	Display_Player(B);//B의 화면 출력
	Display_SaveCard(B_G);//B의 먹은 패 화면 출력

}
//플레이어 C에 대한 명령 입력
void PlayerC(List* C,List* C_G)
{
	printf("C   ");
	Display_Player(C);//C의 화면 출력
	Display_SaveCard(C_G);//C의 먹은패 화면 출력
}

char Command()
{
	char choice;

	printf("명령 : ");
	scanf("%c",&choice); //원하는 명령 고름
	fpurge(stdin); //버퍼를 비워주는 역할을 한다
	

	printf("\n\n");

	return choice; //고른 명령을 리턴시킴
}

void Display_DeckCard(List* _deck) // 현재 덱에 남아있는 카드를 보여준다.
{
	int i=1;
	_deck -> curr = _deck -> head -> next;
	printf("덱에 있는 남은 카드\n");
	while(_deck -> curr != _deck -> tail){
		printf("%s  ",_deck -> curr -> data.cardname); //테일 노드 이전까지 덱에있는 카드를 모두 보여준다 
		if(i%6 == 0) //6번째 카드때 마다 다음줄에 내용을 출력한다 
			printf("\n");
		++i;
		_deck -> curr = _deck -> curr -> next; //그 다음 노드를 확인하기 위해 작성 

	}
	printf("\n\n");
}

void Display_Help()
{
   char choice,check;
   system("clear");
   printf("g : 고\ns : 스톱\ne : 끝내기\nb : 게이머의 잔고보기\nh : 각 키에 대한 설명\n1~7 : 낼 화투 선택\n1~2 : 화투를 냈는데, 깔린 화투 중 무늬는 같으나 다른 값이 있을때\n9 : 9십을 피로 이동\nv : 저장\nl : 로드\n\n");
   printf("e키를 누르면 본래화면으로 돌아갑니다.\n");
   
   input : 
   check = scanf("%c",&choice);
   fpurge(stdin); //버퍼를 비워주는 역할을 한다
   if(choice == 'e'){ //e키를 누르면 본래 화면으로 돌아간다 
	   system("clear");
       return ;
   }

   else if(check != 1 || choice != 'e'){ //잘못된 명령이면 다시 입력해야한다.
   	   printf("다시 입력하세요.\n");
   	   goto input;
   	}
   	printf("\n");
}

void Display_Money(int moneyA,int moneyB, int moneyC) //현재 가지고 있는 돈의 액수
{
	char choice,check;
	system("clear");
	printf("moneyA : %d원\nmoneyB : %d원\nmoneyC : %d원\n",moneyA,moneyB,moneyC); //현재 돈의 액수를 출력해줌 
	printf("e키를 누르면 본래 화면으로 돌아갑니다.\n");
	
    input : 
	check = scanf("%c",&choice);
	fpurge(stdin); //버퍼를 비워주는 역할을 한다


    if(check != 1 || choice != 'e'){ //잘못된 명령이면 재입력 요구 
   	   printf("다시 입력하세요.\n");
   	   goto input;
   	}
   	

	else{
		system("clear");
		return;
	}

}

int Shake(List* player) //흔들기
{
	int i=0;
	int count=0; //흔들기 개수를 센다
	for(i=0;i<12;++i){
	player -> curr = player -> head -> next;
	while(player -> curr != player -> tail) //테일 노드 이전까지 같은 달의 월을 센다 
	{
	     if(player -> curr -> data.month == i+1) //만약 같은 월이 존재하면 count를 한다  
	     	count++;

	     if(count == 3){ //같은 월이 3장 있으면 
			printf("흔들기를 시전하였습니다.\n"); //흔들기가 발동하여 나중에 점수계산시 승자는 점수가 2배가 된다
	     	return 3; //3장 있으므로 3 리턴 
    }
     count = 0;
     player -> curr = player -> curr -> next; //그 다음 노드를 확인하기 위해 작성 
    }
	 player -> curr = NULL;
	}
	 player -> curr = NULL;
    return 0;
}

int ChongTong(List* player) //총통 
{
	int i=0;
	int count=0;
	for(i=0;i<12;++i){
	player -> curr = player -> head -> next;
	while(player -> curr != player -> tail) //테일노드 이전까지 
	{ 
	     if(player -> curr -> data.month == i+1) //같은 월이 존재하면 
	     	count++; //count수를 증가시키고 

	     if(count == 4){ //count수가 4가 되면 
			printf("누군가 총통이 났습니다.\n"); //총통을 발동시켜 승자는 10점을 얻는것으로 끝난다 
	     	return 4; //4장있으므로 4리턴 
		 }

		 else
			 player -> curr = player -> curr -> next; //그 다음 노드를 확인하기 위해 작성 
    }
     count = 0;
     player -> curr = NULL;
    }
	player -> curr = NULL;
    return 0;
}

int Nagari(List* player,List* _deck,int scoreA,int scoreB,int scoreC) //나가리
{
	if(scoreA < 3 && scoreB < 3 && scoreC < 3){ //누구도 3점이 나지 않았을 시에 
		if(player -> head -> next == player -> tail) //게다가 패에 남은것이 아무것도 없었을시에 
	{
      printf("나가리입니다. 다음판을 이기면 점수는 2배~~\n"); //나가리가 발동 
	  return -1;
	}
	
	}

	if(scoreA < 3 && scoreB < 3 && scoreC < 3){ //또는 3점이 나지 않으면서 
		if(_deck -> head -> next == _deck ->tail) //덱에 카드가 하나도 없을시에 
	{
      printf("나가리입니다. 다음판을 이기면 점수는 2배~~\n"); //나가리가 발동 
	  return -1;
	}
	
	}

	
	else
		return 0;
}

List* StealPee(List* taker, List* p1, List* p2) //피 뺏기
{
   p1 -> curr = p1 -> head -> next;
   while(p1 -> curr != p1 -> tail) //p1에서의 패중 피를 뺐는다 
   {
   	   
   	if(p1 -> curr -> data.type == 'P'){ //뺏기는 자의 먹은 패 리스트를 검사해서 데이터 타입이 피이면 
   	   	p1 -> curr -> prev -> next = p1 -> curr -> next; //링크를 끊는다 
   	    p1 -> curr -> next -> prev = p1 -> curr -> prev; //링크를 끊는다

//그리고 뺏은 사람의 링크에 새로 추가한다 
   	    p1 -> curr -> prev = taker -> head; 
   	    p1 -> curr -> next = taker -> head -> next;
   	    taker -> head -> next -> prev = p1 -> curr;
   	    taker -> head -> next = p1 -> curr;

   	    p1 -> curr = NULL;
   	    break;
   	}

	else
		p1 -> curr = p1 -> curr -> next;
   }
   taker -> curr = NULL;
   p1 -> curr = NULL;

   p2 -> curr = p2 -> head -> next;
   while(p2 -> curr != p2 -> tail) //p2에서의 패중 피를 뺐는다 
   {
   	 if(p2 -> curr -> data.type == 'P'){ //뺏기는 자의 먹은 패 리스트를 검사해서 데이터 타입이 피이면 
        p2 -> curr -> prev -> next = p2 -> curr -> next; //링크를 끊는다 
   	    p2 -> curr -> next -> prev = p2 -> curr -> prev; //링크를 끊는다

//그리고 뺏은 사람의 링크에 새로 추가한다 
   	    p2 -> curr -> prev = taker -> head; 
   	    p2 -> curr -> next = taker -> head -> next;
   	    taker -> head -> next -> prev = p2 -> curr;
   	    taker -> head -> next = p2 -> curr;

   	    p2 -> curr = NULL;
   	    break;
   	    }

	 else
		 p2 -> curr = p2 -> curr -> next;
   }
    taker -> curr = NULL;
	p2 -> curr = NULL;
  
	return taker;
}

void Destroy(List* lp) //지정한 리스트를 전부 삭제한다.
{
	Node* temp;  //temp라는 임시변수르 선언하여 
	lp -> curr = lp -> head -> next;
	
	while(lp -> curr != lp -> tail)
	{
		temp = lp -> curr; //temp에 삭제할 노드를 넣고 
        lp -> curr = lp -> curr -> next; //temp 이전노드는 temp의 다음 노드를 가리키게 하고 
		free(temp); //temp를 삭제한다 
	}

	free(lp -> head); //헤드 해제
	free(lp -> tail); //테일 해제
		
}

void Destroy_All(List* A,List* B,List* C,List* A_G,List* B_G,List* C_G,List* _open,List* _deck)//모든 리스트들을 다 삭제
{
	Destroy(A); //A에 대한 리스트들을 전부 소멸시킨다 
	Destroy(B); //B에 대한 리스트들을 전부 소멸시킨다 
	Destroy(C); //C에 대한 리스트들을 전부 소멸시킨다 
	Destroy(A_G); //A_G에 대한 리스트들을 전부 소멸시킨다  
	Destroy(B_G); //B_G에 대한 리스트들을 전부 소멸시킨다 
	Destroy(C_G); //C_G에 대한 리스트들을 전부 소멸시킨다 
	Destroy(_open); //_open에 대한 리스트들을 전부 소멸시킨다 
	Destroy(_deck); //_deck에 대한 리스트들을 전부 소멸시킨다 
}



int Score_Calculate(List* p_g,List* p_g2,List* p_g3,Score* kind) //점수 게산 
{
	
	int count = 0; //count는 0으로 초기화한다 
	int choice; //골라야할 메뉴가 있을시에 필요하다 
	
	p_g -> curr = p_g -> head -> next;
	
	while(p_g -> curr != p_g -> tail){
	//청단
	if(p_g -> curr -> data.cardname == "6청단" || p_g -> curr -> data.cardname == "9청단" || p_g -> curr -> data.cardname == "10청단")
	{
		kind -> CheongDan++; //청단의 수를 세어서 
		if(kind -> CheongDan == 3){ //청단이 3장이면 
			printf("청단 입니다.\n");
			count += 3; //점수에 3점을 추가한다 
		}
	}

	//홍단
	if(p_g -> curr -> data.cardname == "1홍단" || p_g -> curr -> data.cardname == "2홍단" || p_g -> curr -> data.cardname == "3홍단")
	{
		kind -> HongDan++; //홍단의 수를 세어서 
		if(kind -> HongDan == 3){ //홍단이 3장이면 
			printf("홍단 입니다.\n"); 
			count += 3; //점수에 3점을 추가한다
		}
	}

	//초단
	if(p_g -> curr -> data.cardname == "4초단" || p_g -> curr -> data.cardname == "5초단" || p_g -> curr -> data.cardname == "7초단")
	{
		kind -> ChoDan++; //초단의 수를 세어서 
		if(kind -> ChoDan == 3){ //초단이 3장이면 
			printf("초단 입니다.\n"); 
			count += 3; //점수에 3점을 추가한다 
		}
	}

	//오끗
	if(p_g -> curr -> data.type == 'D')
	{
		kind -> Five_End++; //띠가 5장 이상 모이면 
			if(kind -> Five_End >= 5)
				count += ((kind -> Five_End) - 5 + 1); //오끗을 발동하여 1점이 하나씩 추가되도록 한다 
	}

	//피 계산
	if(p_g -> curr -> data.type == 'P')
	{
		if(p_g -> curr -> data.cardname == "11쌍피" || p_g -> curr -> data.cardname == "12쌍피")
		(kind -> Pee) += 2; //쌍피이면 2개 있는 것으로 간주하고 

		else
        (kind -> Pee) ++; //그 이외의 피는 하나씩 센다 

		if((kind -> Pee) >= 10)
        count += ((kind -> Pee) - 10 + 1); //피가 10개이면 그때부터 1점이다.

        
	}

	//열끗
	if(p_g -> curr -> data.type == 'A')
	{
		kind -> Ten_End++; // 열끗을 세서 
		if(kind -> Ten_End >= 5){
			count += ((kind -> Ten_End) - 5 + 1); //열끗이 5개이면 그때부터 1점이다 
			if(kind -> Ten_End >= 7){
				printf("멍텅구리~\n");
				count *= 2; //멍텅구리
			}
		}

		if(p_g -> curr -> data.cardname == "3새" || p_g -> curr -> data.cardname == "4새" || p_g -> curr -> data.cardname == "8새")
		{
			kind -> Go_Dori++; //고도리
			if(kind -> Go_Dori == 3){ //새 그림이 3장이면 
				printf("고도리~\n");
				count += 5; //고도리를 발동하여 5점을 추가한다 
			}
		}

	}

	//광 계산
	if(p_g -> curr -> data.type == 'G')
	{
		kind -> Gwang++;
		if(kind -> Gwang == 3){
			
			if(p_g -> curr -> data.month == 12){ //12월의 비광이 있으면 
				printf("3광 입니다.\n"); //비3광일 경우에는 2점이 추가된다 
				count+=2;
			}

			else{
				printf("3광 입니다.\n");  //그외에는 광이 3장이면 
				count +=3; //3점을 얻는다 
			}
		}

		else if(kind -> Gwang == 4){ //광이 4장이면 
			printf("4광 입니다.\n");
			count += 4; //4점을 얻고 
		}

		else if(kind -> Gwang == 5){ //광이 5장이면 
			printf("5광 입니다.\n");
			count += 15; //15점을 얻는다
		}
	}

	//국진 계산
	if(p_g -> curr -> data.cardname == "9국진")
		{
			
			if(count >= 1){ //점수가 1점이라도 났을 경우에는 
				printf("9국진을 피로 쓰시겠습니까?(사용 : 9,미사용 : any key) ");
				scanf("%d",&choice); //국진을 피로 사용할지 결정해서 
				fflush(stdin);
				#warning did commented
				fpurge(stdin); 
				if(choice == 9){ //국진을 피로 쓰면 
				strcpy(p_g -> curr -> data.cardname,"9국진(피)");
				p_g -> curr -> data.type = 'P'; //데이터타입이 피로 바뀌고 
				kind -> Pee += 2; //쌍피 역할을 한다.
				}
				else 
					;
		}
			else
          p_g -> curr = p_g -> curr -> next; //그 외에 해당되는 사항이 없으면 다음 노드를 확인한다.
	
	}
	p_g -> curr = p_g -> curr -> next;
	}
	
	p_g -> curr = NULL;
	kind -> CheongDan = 0;   
	kind -> HongDan = 0;
	kind -> ChoDan = 0;
	kind -> Pee = 0;         // 각각 해당하는 점수를 모두 계산한 뒤에 
	kind -> Gwang = 0;       // 다시 0으로 초기화 한다.
	kind -> Five_End = 0;
	kind -> Ten_End = 0;
	kind -> Go_stop = 0;
	kind -> Pee_BakB = 0;
	kind -> Pee_BakC = 0;
	kind -> Gwang_BakB = 0;
	kind -> Gwang_BakC = 0;
	kind -> Go_Dori = 0;
	kind -> Gook_Jin = 0;
	

    return count; //그리고 이미 세어진 count수를 리턴 한다.
}




int Bak_Calculate(List* p_g2,List* p_g3,int count,int go,int go2,int go3,int shake,int nagari_count,Score* kind) //박 계산 하기
{
	int i=0;
//광박
	p_g2 -> curr = p_g2 -> head -> next;
	p_g3 -> curr = p_g3 -> head -> next;
	
    while(p_g2 -> curr != p_g2 -> tail)
	{
		if(p_g2 -> curr -> data.type == 'G') //패자의 먹은 패 리스트에서 광을 확인하고 
			kind -> Gwang_BakB++; //있다면 그 수를 증가시킨다 

		p_g2 -> curr = p_g2 -> curr -> next;
	}

	while(p_g3 -> curr != p_g3 -> tail)
	{
		if(p_g3 -> curr -> data.type == 'G') //패자의 먹은 패 리스트에서 광을 확인하고 
			kind -> Gwang_BakC++; //있다면 그 수를 증가시킨다 

		p_g3 -> curr = p_g3 -> curr -> next;
	}

	if(kind -> Gwang_BakB == 0 && kind -> Gwang_BakC == 0) //만약 두 패자 모두 광이 없으면 광박이 발동한다 
		count *= 4; //이때 승자는 점수의 4배를 더 얻음 

	else if(kind -> Gwang_BakB != 0 && kind -> Gwang_BakC == 0) //한 명 만 광이 없으면 광박이 발동한다
		count *= 2; //이때 승자는 점수의 2배를 더 얻음 

	else if(kind -> Gwang_BakB == 0 && kind -> Gwang_BakC != 0) //한 명 만 광이 없으면 광박이 발동한다
		count *= 2; //이 때 승자는 점수의 2배를 더 얻음 

	p_g2 -> curr = NULL;
	p_g3 -> curr = NULL;

	//피박
	p_g2 -> curr = p_g2 -> head -> next;
	p_g3 -> curr = p_g3 -> head -> next;
	
    while(p_g2 -> curr != p_g2 -> tail)
	{
		if(p_g2 -> curr -> data.type == 'P') //패자의 먹은 패 리스트에서 피를 확인하고 
			kind -> Pee_BakB++; //있을때 마다 피의 수를 증가시킨다.

		p_g2 -> curr = p_g2 -> curr -> next;
	}

	while(p_g3 -> curr != p_g3 -> tail)
	{
		if(p_g3 -> curr -> data.type == 'P') //패자의 먹은 패 리스트에서 피를 확인하고 
			kind -> Pee_BakC++; //있을때 마다 피의 수를 증가시킨다.

		p_g3 -> curr = p_g3 -> curr -> next;
	}

	if(kind -> Pee_BakB < 6 && kind -> Pee_BakC < 6) //만약 두 패자 모두 피가 6장 미만이면 
		count *= 4; //승자는 점수의 4배를 더 얻는다 

	else if(kind -> Pee_BakB >= 6 && kind -> Pee_BakC < 6) //만약 한 패자만 피가 6장 미만이면 
		count *= 2; //승자는 점수의 2배를 더 얻는다 

	else if(kind -> Pee_BakB < 6 && kind -> Pee_BakC >= 6) //만약 한 패자만 피가 6장 미만이면 
        count *= 2; //승자는 점수의 2배를 더 얻는다 

	//고 계산
	if(go == 1) //1고 이면 점수에 1점 추가 
		count ++;
	
	else if(go == 2) //2고이면 점수에 2점 추가 
		count += 2;

	else if(go > 2){
		for(i=0;i<(go-2);++i) //3고 이상부터는 고 횟수가 증가할때 마다 점수를 2배한다.
		count *= 2;
	}
	


	//고박
	if(go >= 1 && (go2>=1 || go3>=1))
		count *= 2; //고를 외쳤는데 다른 사람이 점수가 나서 스톱을 외치면 고박이 난다 

	
	p_g2 -> curr = NULL;
	p_g3 -> curr = NULL;

	//나가리
	if(nagari_count == 1) //나가리가 존재하면 
		count *= 2; //점수를 2배한다 

	else if(nagari_count > 1){
		for(i=0;i<(nagari_count-1);++i) //나가리가 몇번이상 났으면 
			count *= 2; //난 횟수만큼 점수를 2배씩  계속 한다.
	}

	//흔들기
	if(shake == 3)
		count *= 2; //흔들어서 이길 경우 점수가 2배이다 


	return count; //지금까지 누적한 점수를 모두 리턴한다.
}

int Display_Score(int score) //점수 표시
{
	printf("(SCORE : %d) ",score);
	printf("\n\n");
	return score;
}


int Money_Calculate_Get(int score,int moneyA) //승자는 각 플레이어로부터 점수의 100배만큼의 돈을 얻는다.
{
	moneyA += (score * 200);
	return moneyA;
}

int Money_Calculate_Minus(int score,int moneyB) //패자는 승자의 점수의 100배 만큼의 돈을 잃는다.
{
	moneyB -= (score * 100);
	return moneyB;
}

int Money_Calculate_Minus2(int score,int moneyC) //패자는 승자의 점수의 100배 만큼의 돈을 잃는다.
{
	moneyC -= (score * 100);
	return moneyC;
}
		
int Save(Card* Asave,Card* Bsave,Card* Csave,Card* A_Gsave,Card* B_Gsave,Card* C_Gsave,Card* _opensave,Card* _decksave,List* A,List* B,List* C,List* A_G,List* B_G,List* C_G,List* _open,List* _deck,int* nagari,int* shake,int* go,int* score,int* money,int* temp)
{
	FILE* ifp = NULL;
	

	ifp = fopen("save.txt","w"); //save.txt라는 텍스트 파일을 쓰기용으로 오픈한다.
	
	temp[0] = GetListNum(A);  //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[1] = GetListNum(B); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[2] = GetListNum(C); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[3] = GetListNum(A_G); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[4] = GetListNum(B_G); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[5] = GetListNum(C_G); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[6] = GetListNum(_open); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	temp[7] = GetListNum(_deck); //각 리스트들의 수를 세어서 temp에 각 수를 저장한다.
	
	
    A -> curr = A -> head -> next;
	B -> curr = B -> head -> next;
	C -> curr = C -> head -> next;
	A_G -> curr = A_G -> head -> next;
	B_G -> curr = B_G -> head -> next;
	C_G -> curr = C_G -> head -> next;
	_open -> curr = _open -> head -> next;
	_deck -> curr = _deck -> head -> next;

	int i = 0;
	while(A -> curr != A -> tail){
		fprintf(ifp,"%d\n",Asave[i].month = A -> curr -> data.month);
		strcpy(Asave[i].cardname,A -> curr -> data.cardname);
		fprintf(ifp,"%s\n",Asave[i].cardname);
		fprintf(ifp,"%c\n",Asave[i].type = A -> curr -> data.type);
		A -> curr = A -> curr -> next;
		i++;
	}
	
	i=0;
	while(B -> curr != B -> tail){
		fprintf(ifp,"%d\n",Bsave[i].month = B -> curr -> data.month);
		strcpy(Bsave[i].cardname,B -> curr -> data.cardname);
		fprintf(ifp,"%s\n",Bsave[i].cardname);
		fprintf(ifp,"%c\n",Bsave[i].type =B -> curr -> data.type);
		B -> curr = B -> curr -> next;
		i++;
	}
	
	i=0;
	while(C -> curr != C -> tail){
		fprintf(ifp,"%d\n",Csave[i].month = C -> curr -> data.month);
		strcpy(Csave[i].cardname,C -> curr -> data.cardname);
		fprintf(ifp,"%s\n",Csave[i].cardname);
		fprintf(ifp,"%c\n",Csave[i].type = C -> curr -> data.type);
		C -> curr = C -> curr -> next;
		i++;
	}
	
	i=0;
	while(A_G -> curr != A_G -> tail){
		fprintf(ifp,"%d\n",A_Gsave[i].month = A_G -> curr -> data.month);
		strcpy(A_Gsave[i].cardname,A_G -> curr -> data.cardname);
		fprintf(ifp,"%s\n",A_Gsave[i].cardname);
		fprintf(ifp,"%c\n",A_Gsave[i].type = A_G -> curr -> data.type);
		A_G -> curr = A_G -> curr -> next;
		i++;
	}
	
	i=0;
	while(B_G -> curr != B_G -> tail){
		fprintf(ifp,"%d\n",B_Gsave[i].month = B_G -> curr -> data.month);
		strcpy(B_Gsave[i].cardname,B_G -> curr -> data.cardname);
		fprintf(ifp,"%s\n",B_Gsave[i].cardname);
		fprintf(ifp,"%c\n",B_Gsave[i].type = B_G -> curr -> data.type);
		B_G -> curr = B_G -> curr -> next;
		i++;
	}
	
	i=0;
	while(C_G -> curr != C_G -> tail){
		fprintf(ifp,"%d\n",C_Gsave[i].month = C_G -> curr -> data.month);
		strcpy(C_Gsave[i].cardname,C_G -> curr -> data.cardname);
		fprintf(ifp,"%s\n",C_Gsave[i].cardname);
		fprintf(ifp,"%c\n",C_Gsave[i].type = C_G -> curr -> data.type);
		C_G -> curr = C_G -> curr -> next;
		i++;
	}
	
	i=0;
	while(_open -> curr != _open -> tail){
		fprintf(ifp,"%d\n",_opensave[i].month = _open -> curr -> data.month);
		strcpy(_opensave[i].cardname,_open -> curr -> data.cardname);
		fprintf(ifp,"%s\n",_opensave[i].cardname);
		fprintf(ifp,"%c\n",_opensave[i].type = _open -> curr -> data.type);
		_open -> curr = _open -> curr -> next;
		i++;
	}
	
	i=0;
	while(_deck -> curr != _deck -> tail){
		fprintf(ifp,"%d\n",_decksave[i].month = _deck -> curr -> data.month);
		strcpy(_decksave[i].cardname,_deck -> curr -> data.cardname);
		fprintf(ifp,"%s\n",_decksave[i].cardname);
		fprintf(ifp,"%c\n",_decksave[i].type = _deck -> curr -> data.type);
		_deck -> curr = _deck -> curr -> next;
		i++;

     }
	
	for(i=0;i<3;++i)
	fprintf(ifp,"%d\n",nagari[i]);
	
	for(i=0;i<3;++i)
	fprintf(ifp,"%d\n",shake[i]);
	
	for(i=0;i<3;++i)
	fprintf(ifp,"%d\n",go[i]);
	
	for(i=0;i<3;++i)
	fprintf(ifp,"%d\n",score[i]);
	
	for(i=0;i<3;++i)
	fprintf(ifp,"%d\n",money[i]);
	
	
    A -> curr = NULL;
	B -> curr = NULL;
	C -> curr = NULL;
	A_G -> curr = NULL;
	B_G -> curr = NULL;
	C_G -> curr = NULL;
	_open -> curr = NULL;
	_deck -> curr = NULL;

	printf("저장하였습니다.\n");
	fclose(ifp);

	return 1; //Save를 성공하면 1값을 반환

}
void Load(Card* Asave,Card* Bsave,Card* Csave,Card* A_Gsave,Card* B_Gsave,Card* C_Gsave,Card* _opensave,Card* _decksave,List* A,List* B,List* C,List* A_G,List* B_G,List* C_G,List* _open,List* _deck,int* nagari,int* shake,int* go,int* score,int* money,int saveA,int saveB,int saveC,int* temp)
{
	FILE* ofp = NULL;

	if((ofp = fopen("save.txt","r")) == NULL){ //save.txt란 텍스트파일을 읽기전용으로 연다.
		printf("존재하지 않는 데이터 입니다\n");
	    return ;
	}

	Destroy_All(A,B,C,A_G,B_G,C_G,_open,_deck); //모든 노드를 삭제하고 
	Create_All_Lists(A,B,C,A_G,B_G,C_G,_open,_deck); //다시 재생성한다.

	Create(A,temp[0]); //그리고 temp에 저장된 숫자만큼 각 리스트를 생성한다.
	Create(B,temp[1]);
	Create(C,temp[2]);
	Create(A_G,temp[3]);
	Create(B_G,temp[4]);
	Create(C_G,temp[5]);
	Create(_open,temp[6]);
	Create(_deck,temp[7]);
	
	A -> curr = A -> head ->next;
	B -> curr = B -> head ->next;
	C -> curr = C -> head ->next;
	A_G -> curr = A_G -> head ->next;
	B_G -> curr = B_G -> head ->next;
	C_G -> curr = C_G -> head ->next;
	_open -> curr = _open -> head ->next;
	_deck -> curr = _deck -> head ->next;

	
    int i = 0;
	while(A -> curr != A -> tail){
		A -> curr -> data.month = Asave[i].month;
		A -> curr -> data.type = Asave[i].type;
		fscanf(ofp," %d ",&(A -> curr -> data.month));
		strcpy(A -> curr -> data.cardname,Asave[i].cardname);
	    fscanf(ofp," %s ",A -> curr -> data.cardname);
		fscanf(ofp," %c ",&(A -> curr -> data.type));
		A -> curr = A -> curr -> next;
		++i;
	}
	i=0;
	while(B -> curr != B -> tail){
		B -> curr -> data.month = Bsave[i].month;
		B -> curr -> data.type = Bsave[i].type;
		fscanf(ofp," %d ",&(B -> curr -> data.month));
		strcpy(B -> curr -> data.cardname,Bsave[i].cardname);
		fscanf(ofp," %s ",B -> curr -> data.cardname);
		fscanf(ofp," %c ",&(B -> curr -> data.type));
		B -> curr = B -> curr -> next;
		i++;
	}
	i=0;
	while(C -> curr != C -> tail){
		C -> curr -> data.month = Csave[i].month;
		C -> curr -> data.type = Csave[i].type;
		fscanf(ofp," %d ",&(C -> curr -> data.month));
		strcpy(C -> curr -> data.cardname,Csave[i].cardname);
		fscanf(ofp," %s ",C -> curr -> data.cardname);
		fscanf(ofp," %c ",&(C -> curr -> data.type));
		C -> curr = C -> curr -> next;
		i++;
	}
	i=0;
	while(A_G -> curr != A_G -> tail){
		A_G -> curr -> data.month = A_Gsave[i].month;
		A_G -> curr -> data.type = A_Gsave[i].type;
		fscanf(ofp," %d ",&(A_G -> curr -> data.month));
		strcpy(A_G -> curr -> data.cardname,A_Gsave[i].cardname);
		fscanf(ofp," %s ",A_G -> curr -> data.cardname);
		fscanf(ofp," %c ",&(A_G -> curr -> data.type));
		A_G -> curr = A_G -> curr -> next;
		i++;
	}
	i=0;
	while(B_G -> curr != B_G -> tail){
		B_G -> curr -> data.month = B_Gsave[i].month;
		B_G -> curr -> data.type = B_Gsave[i].type;
		fscanf(ofp," %d ",&(B_G -> curr -> data.month));
		strcpy(B_G -> curr -> data.cardname,B_Gsave[i].cardname);
		fscanf(ofp," %s ",B_G -> curr -> data.cardname);
		fscanf(ofp," %c ",&(B_G -> curr -> data.type));
		B_G -> curr = B_G -> curr -> next;
		i++;
	}
	i=0;
	while(C_G -> curr != C_G -> tail){
		C_G -> curr -> data.month = C_Gsave[i].month;
		C_G -> curr -> data.type = C_Gsave[i].type;
		fscanf(ofp," %d ",&(C_G -> curr -> data.month));
		strcpy(C_G -> curr -> data.cardname,C_Gsave[i].cardname);
		fscanf(ofp," %s ",C_G -> curr -> data.cardname);
		fscanf(ofp," %c ",&(C_G -> curr -> data.type));
		C_G -> curr = C_G -> curr -> next;
		i++;
	}

	i=0;
	while(_open -> curr != _open -> tail){
		_open -> curr -> data.month = _opensave[i].month;
		_open -> curr -> data.type = _opensave[i].type;
		fscanf(ofp," %d ",&(_open -> curr -> data.month));
		strcpy(_open -> curr -> data.cardname,_opensave[i].cardname);
		fscanf(ofp," %s ",_open -> curr -> data.cardname);
		fscanf(ofp," %c ",&(_open -> curr -> data.type));
		_open -> curr = _open -> curr -> next;
		i++;
	}

	i=0;
	while(_deck -> curr != _deck -> tail){
		_deck -> curr -> data.month = _decksave[i].month;
		_deck -> curr -> data.type = _decksave[i].type;
		fscanf(ofp," %d ",&(_deck -> curr -> data.month));
		strcpy(_deck -> curr -> data.cardname,_decksave[i].cardname);
		fscanf(ofp," %s ",_deck -> curr -> data.cardname);
		fscanf(ofp," %c ",&(_deck -> curr -> data.type));
		_deck -> curr = _deck -> curr -> next;
		i++;
	}

	for(i=0;i<3;++i)
	fscanf(ofp,"%d",&(nagari[i]));
	
	for(i=0;i<3;++i)
	fscanf(ofp,"%d",&(shake[i]));
	
	for(i=0;i<3;++i)
	fscanf(ofp,"%d",&(go[i]));
	
	for(i=0;i<3;++i)
	fscanf(ofp,"%d",&(score[i]));
	
	for(i=0;i<3;++i)
	fscanf(ofp,"%d",&(money[i]));
	
	
	
    A -> curr = NULL;
	B -> curr = NULL;
	C -> curr = NULL;
	A_G -> curr = NULL;
	B_G -> curr = NULL;
	C_G -> curr = NULL;
	_open -> curr = NULL;
	_deck -> curr = NULL;

	system("clear");
	    if(saveA == 1)
	    printf("*");
	    PlayerA(A,A_G);
		Display_Score(score[0]); //A의 점수
		if(saveB == 1)
		printf("*");
		PlayerB(B,B_G);
		Display_Score(score[1]); //B의 점수
		if(saveC == 1)
		printf("*");
		PlayerC(C,C_G);
		Display_Score(score[2]); //C의 점수
		Display_OpenCard(_open); //현재 깔린 패 화면 출력
		Display_DeckCard(_deck); //덱에 있는 카드들을 출력
		

    
	fclose(ofp);
}
