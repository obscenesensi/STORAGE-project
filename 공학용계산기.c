#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPR_SIZE 100
#define MAX_MYSTACK_SIZE 50


typedef enum 
{lparen,rparen,plus,minus,times,devide,mod,
eos,operand,sign_m,sign_p,my_sin,my_cos,my_tan} precendence;

static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0, 0, 0, 0, 0, 0};       
// 스택에 있을때 isp[8],isp[9]=21 최고수준유지..
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0, 21, 21, 21, 21, 21};     
// 스택에 들어갈때
//# & 연산자는 스택엔 무조건 저장했다가.. 다른연산자 만나면 무조건 꺼낸다.

char expr[MAX_EXPR_SIZE];

double stack[MAX_MYSTACK_SIZE]; // 스택선언.. 동적할당은 않는다.
int top;    // 스택 tp 선언.. stack_init()으로 초기화.. -1

void stack_init();
void push(double);
double pop();

precendence get_token(char*);
char printf_token(int);

void postfix(char*,char*);              //중위 표현 으로..
double eval(char*);                     //후위 표현 으로 컨버팅... 정수만..
void tri_funtion(char*,char*);          //삼각 함수를 압축 따로 계산..

double my_sin_fct(char*);
double my_cos_fct(char*);
double my_tan_fct(char*);

int main(void)
{
    int i=0;
    char input_char;
    /* 입력 문자열 */
    char expr_temp[MAX_EXPR_SIZE];

    printf("수식입력하시오\n");

    while((input_char=getchar()) != '\n')   //문자열 입력받음..
        expr[i++]=input_char;
    expr[i]='\0';   // 마지막에 널문자.
    
    tri_funtion(expr,expr_temp);        
    // 일단 삼각 함수 모두 계산하여 정수 중위표현만 넘긴다. 
    
    printf("변환 확인:%s\n",expr_temp);
    postfix(expr_temp,expr_temp);
    printf("후위표현..%s\n", expr_temp);
    eval(expr_temp);
    printf("최종결과:%f\n",eval(expr_temp));
//  printf("sin30=%f",sin(30*3.141592/180));

    return 0;
}


/*----------stack funtion-----------------*/
void push(double temp) { stack[++top]=temp; }
void stack_init() { top = -1; }
double pop() { return stack[top--]; }
/*----------------------------------------*/

/*-------convert data---------------------*/
precendence get_token(char* input)
{
    switch(*input){
        case '('    : return lparen;
        case ')'    : return rparen;
        case '+'    : return plus;
        case '-'    : return minus;
        case '*'    : return times;
        case '/'    : return devide;
        case '%'    : return mod;
        case '&'    : return sign_m;
        case '#'    : return sign_p;
        case 's'    : return my_sin;
        case 'c'    : return my_cos;
        case 't'    : return my_tan;
        case '\0'   : return eos;
        default     : return operand;
    }
}

char printf_token(int precendence)
{
    switch(precendence){
        //----------------------------------------//
        case sign_m : return '&';   // * -1
        case sign_p : return '#';   // * 1
        //----------------------------------------//
        case my_sin : return 's';
        case my_cos : return 'c';
        case my_tan : return 't';
        //----------------------------------------//
        case plus   : return '+';
        case minus  : return '-';
        case times  : return '*';
        case devide : return '/';
        default : return '%';
    }
}

void postfix(char* input,char* output)  
//후위 표현으로 바꾼 string을.. strcpy(input,output);
{
    precendence token;
    int j=0, k=0, sign=0, flag=1;
    char temp_num[100];

    stack_init();           // 스택 초기화
    push(eos);              // stack의 첫번째 요소에..eos

    while((token = get_token(input+j))!=eos)
    {
        sign=0;     //sign 초기화..
    //-------minus sign 판별..---- 수식 / 부호 => 0 /1  --------//
        if((token==minus))
        {
            if(j==0 && (get_token(input+j+1)==minus))  // 처음 - - 이면..
                sign=-1;        
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==operand))     // 수식 - 숫자 일때..
                sign=1;     //부호인 경우는 오로지 한개다....
            else if((get_token(input+j-1)==rparen) && (get_token(input+j+1)!=operand))      // ) - 수식..
                sign=0;
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==lparen))      // 수식 - ( 이면..
                sign=-1;    //좌 괄호 앞은 *-1 이다.
            else if((get_token(input+j-1)==rparen) && (get_token(input+j-1)!=operand))      // 수식 - ( 이면..
                sign=-1;    //좌 괄호 앞은 *-1 이다
            else if((get_token(input+j-1)!=operand) && isalpha(*(input+j+1)))       // 수식 - sin 이면..
                sign=-1;
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==minus))       // 수식 - - 이면..
                sign=-1;    // 수식 사이의 -는 *-1 이다.
            else                    // 숫자 - 숫자
                sign=0;
        }
    //----------------------------------------------------------//

    //--------plus sign 판별..---- 수식 / 부호 => 0 /1  --------//
        if((token==plus))
        {
            if(j==0 && (get_token(input+j+1)==plus))        // 처음 + + 이면..
                sign=-2;
            else if((get_token(input+j-1)!=operand) && isalpha(*(input+j+1)))       // ) - 문자 이면..
                sign=-2;
            else if((get_token(input+j-1)==rparen) && (get_token(input+j+1)!=operand))      // ) - 수식..
                sign=0;
            else if((get_token(input+j-1)!=operand) && isalpha(*(input+j+1)))       // 수식 - sin 이면..
                sign=-2;
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==operand))     // 수식 + 숫자 일때..
                sign=1; //부호..
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==lparen))      // 수식 + ( 이면..
                sign=0;
            else if((get_token(input+j-1)!=operand) && (get_token(input+j+1)==plus))        // 수식 + + 이면..
                sign=-2;
            else                        //숫자 + 숫자
                sign=0;
        }
    //----------------------------------------------------------//
//      printf("sign=%d\n",sign);
        if(sign==-3)    // 에러 플래그 띄울까?
        {
            printf("input error!!!!\n");
            exit(1);
        }
        else if(sign==-2)
        {
            j++;
            push(sign_p);
            continue;
        }
        else if(sign==-1)       // * -1 처리..
        {
            j++;        
            push(sign_m);   // -() 처리.. 스택저장하고 루프끝냄.. &&..
            continue;
        }

        else if(sign==0)        // 해당인덱스가 부호가 아닐때.. 원래대로 처리..
        {
            if (token == operand)
            {
                *(temp_num+k++) = *(input+j);
                if(!isdigit(*(input+j+1)) && (*(input+j+1)!='.') && !isalpha(*(input+j+1)) && (stack[top]==9||stack[top]==8) )  // # & 가 숫자 앞에 있을경우 끄집는다.
                {   // 뒤에가 소숫점, 숫자, 문자가 아닐경우.. 숫자 종료..
                    while(stack[top]==9 || stack[top]==8)   // 좌괄호 나올때까지.. pop()..
                    {
                            *(temp_num+k++)=' ';
                            *(temp_num+k++) = printf_token((int)pop());
                            *(temp_num+k++)=' ';
                    }
                }
            }
            
            else if (token == rparen)       // 우괄호..
            {
                while(stack[top]!=lparen)   // 좌괄호 나올때까지.. pop()..
                {
                    *(temp_num+k++)=' ';
                    *(temp_num+k++) = printf_token((int)pop());
                }
                pop();  // 좌골호 또한. pop
                //----좌괄호 옆에 삼각함수 있으면 끄집어 내라.------//
                if(stack[top]==my_sin)
                {
                    *(temp_num+k++)=' ';
                    *(temp_num+k++) = printf_token((int)pop());
                }
                if(stack[top]==my_cos)
                {
                    *(temp_num+k++)=' ';
                    *(temp_num+k++) = printf_token((int)pop());
                }
                if(stack[top]==my_tan)
                {
                    *(temp_num+k++)=' ';
                    *(temp_num+k++) = printf_token((int)pop());
                }
                //---------------------------------------------------//
                

            }

            else
            {
                if((get_token(input+j-1)==operand) && (token==lparen))  //숫자() 곱셈치환..
                {
                    push(times);
                }
                if((get_token(input+j-1)!=lparen) && !isalpha(*(input+j)) && (stack[top]==9||stack[top]==8) )   // # & 가 숫자 앞에 있을경우 끄집는다.
                {   // 뒤에가 소숫점, 숫자, 문자가 아닐경우.. 숫자 종료..
                    while(stack[top]==9 || stack[top]==8)   // 좌괄호 나올때까지.. pop()..
                    {
                            *(temp_num+k++)=' ';
                            *(temp_num+k++) = printf_token((int)pop());
                            *(temp_num+k++)=' ';
                    }
                }
                while(isp[(int)stack[top]]>=icp[token])     //현재 스택포인터와 들어갈 자료 비교.
                {
                    *(temp_num+k++)=' ';
                    *(temp_num+k++) = printf_token((int)pop());
                }



                
                push(token);
                *(temp_num+k++)=' ';    // 숫자 끝나면 공백 넣어라.
            }
        }
        else            // 해당인덱스가 부호 일때.. 그냥 프린트..
        {
            *(temp_num+k++) = *(input+j);
            sign=0; // 부처리후 다시 초기화..
        }
        j++;        
    }

    while((token = (int)pop())!=eos)//스택에 나머지있는거 다 출력
    {
        *(temp_num+k++)=' ';
        *(temp_num+k++) = printf_token(token);
    }
    *(temp_num+k++)=' ';    // 후위 표현 연산뒤 강제로 공백삽입
    temp_num[k]='\0';       
    strcpy(output,temp_num);
}




double eval(char* postfix)
{
    int i=0,j=0;
    char temp_num[10];  // atof 쓰기위한 임시 배열..
    int flag=0;
    double op1,op2;
    
    stack_init();   //stack을 쓰기 위한 다시 초기화.
        
    while(*(postfix+i)!='\0')
    {
        //printf("현재 스택값 : %f \n",stack[top]);
        //----- 일반 숫자열계산. --------------------------------------------------------------//
        if(*(postfix+i)==' ')
        {
            i++;        // 일단 공백 제거..
            continue;   // 인덱스는 바로 옮긴다.
        }
        else if(isdigit(*(postfix+i+1)))    // 뒤에가 숫자면.. 부호이므로... atof 변환하여 스택저장.
        {
            while((*(postfix+i)!=' '))
            {
                temp_num[j++]=*(postfix+i++);
            }
            
            temp_num[j]='\0';       // temp_num을 마무리
            push(atof(temp_num));   // push 하여 스택에 저장..
            j=0;                    // temp_num을 다시 초기화 해서 쓴다.
        }
        else if(isdigit(*(postfix+i)))  // 해당 인덱스하 한자리 숫자일경우..
        {
            while(*(postfix+i)!=' ')
                temp_num[j++]=*(postfix+i++);
            temp_num[j]='\0';       // temp_num을 마무리
            push(atof(temp_num));   // push 하여 스택에 저장..
            j=0;                    // temp_num을 다시 초기화 해서 쓴다.
        }
        else if(*(postfix+i)=='&')  // -( ) 처리..
            stack[top] = stack[top] * -1;
        else if(*(postfix+i)=='#')  // +( ) 처리..
            stack[top] = stack[top] * 1;
        else if(*(postfix+i)=='s')
            stack[top] = sin(stack[top]*3.141592/180);
        else if(*(postfix+i)=='c')
            stack[top] = cos(stack[top]*3.141592/180);
        else if(*(postfix+i)=='t')
            stack[top] = tan(stack[top]*3.141592/180);
        else
        {
            op2 = pop();    
            op1 = pop();
            switch(get_token(postfix+i))
            {
                case plus : 
                {
                    push(op1 + op2);
                    break;
                }
                case minus : 
                {
                    push(op1 - op2);
                    break;
                }
                case times : 
                {
                    push(op1 * op2);
                    break;
                }
                case devide : 
                {
                    push(op1 / op2);
                    break;
                }
                case mod : 
                {
                    push((int)op1 % (int)op2);
                    break;
                }
            }
        }
        //------------------------------------------------------------------------------//
        i++;    // 무사히 한번돌면 인덱스 증가. 단 공백은 바로.. continue
    }

//  printf("최종결과:%f",stack[top]);   // stack에 최종남아있는것이 값.
    return stack[top];
}

void tri_funtion(char* input,char* output)
{
    char tri_result[MAX_EXPR_SIZE];
    char temp_arr[10];  // s c t 임시 검사용..
    int i=0, j=0, z=0;

    while(*(input+i)!='\0')
    {
//      tri_result[z++] = *(*(input+i));
        
        if(isalpha(*(input+i))!=0) // 숫자,문자=0 // 대문자=1 // 소문자=2   //문자일경우.. 루프..
        {
            char char_sin[] = {"sin"};
            char char_cos[] = {"cos"};
            char char_tan[] = {"tan"};

            //--------- s c t 검사후 문자열 변환.. ------------------//
            for(j=0;j<3;j++)        // 삼각함수 문자열 저장..() 했을때..
                temp_arr[j]=*(input+i+j);
            temp_arr[j]='\0';

            if(!strncmp(temp_arr,char_sin,3))
            {
                tri_result[z++] = 's';
                i+=3;   // 만약 sin 들어오면.. 인덱스 3 옮기고 루프 종료.
                continue;
            }
            else if (!strncmp(temp_arr,char_cos,3))
            {
                tri_result[z++] = 'c';
                i+=3;   // 만약 cos 들어오면.. 인덱스 3 옮기고 루프 종료.
                continue;
            }
            else if (!strncmp(temp_arr,char_tan,3))
            {
                tri_result[z++] = 't';
                i+=3;   // 만약 tan 들어오면.. 인덱스 3 옮기고 루프 종료.
                continue;
            }               
            else
            {
                printf("input data is error"); // 잘못된 데이터면 프로그램 강제종료.
                exit(1);
            }
        }
            //--------- s c t 검사후 문자열 변환.. ------------------//
        else
            tri_result[z++] = *(input+i);
        i++;
    }
    tri_result[z]='\0';

//  printf("test:%s\n",tri_result);
    strcpy(output,tri_result);
    
}


/*
double my_sin_fct(char* input)
{
    char temp_tri_sin[50];
    double result;

    postfix(input,temp_tri_sin);    // 들어온 스트링을 후위 표현으로 계산후..
    eval(temp_tri_sin);             // 그 인자를 연산하여..
    
    result = sin(eval(temp_tri_sin)*3.141592/180);  // 최종 사인값으로..

    return result;
}

double my_cos_fct(char* input)
{
    char temp_tri_cos[50];
    double result;

    postfix(input,temp_tri_cos);    // 들어온 스트링을 후위 표현으로 계산후..
    eval(temp_tri_cos);             // 그 인자를 연산하여..
    
    result = cos(eval(temp_tri_cos)*3.141592/180);  // 최종 사인값으로..

    return result;
}

double my_tan_fct(char* input)
{
    char temp_tri_tan[50];
    double result;

    postfix(input,temp_tri_tan);    // 들어온 스트링을 후위 표현으로 계산후..
    eval(temp_tri_tan);             // 그 인자를 연산하여..
    
    result = tan(eval(temp_tri_tan)*3.141592/180);  // 최종 사인값으로..

    return result;
}
