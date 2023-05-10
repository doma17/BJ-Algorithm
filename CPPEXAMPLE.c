#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct { 
   element* data; //스택 안에 있는 데이터
   int top; //스택의 top
   int size; //스택의 사이즈
}StackType;

//스택 초기화 함수
void Stackinit(StackType* s, int n) {
   s->data = (element*)malloc(n * sizeof(element)); //n크기의 데이터를 담을 수 있도록 동적 할당
   s->top = -1; //top은 -1
   s->size = n; //스택의 사이즈는 n
}

//포화 상태 검출 함수
int is_full(StackType* s) {
   return (s->top == (s->size - 1)); //꽉 찼다면 리턴
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
   return(s->top == -1); //top이 -1,즉 비어있다면 리턴
}

//삽입함수
void push(StackType* s, element item) {
   //포화 상태라면 사이즈의 크기를 두배만큼 재할당
   if (is_full(s)) {
      s->size *= 2;
      s->data = (element*)realloc(s->data, s->size * sizeof(element));
   }
   else {
      s->data[++(s->top)] = item; //포화 상태가 아니면 top을 하나 증가시켜 값을 대입
   }
}

//삭제함수
element pop(StackType* s) {
   //공백 상태면 에러 메세지 출력
   if (is_empty(s)) {
      printf("스택 공백 에러\n");
   }
   else {
      return(s->data[(s->top)--]); //공백 상태가 아니면 top 위치의 값을 리턴하고 제거 후 top을 하나 줄임
   }
}

//배열의 요소를 스택에 저장하는 함수
void put_to_stack(int* arr, StackType* s, int n) {
   //배열의 크기, 즉 n번 째 요소까지 저장
   for (int i = 0;i < n; i++) {
      push(s, arr[i]);
   }
}

//스택의 요소를 배열에 저장하는 함수
void put_to_array(int* arr, StackType* s) {
   //스택의 크기만큼 반복해서 배열에 저장
   for (int i = 0;i < s->size; i++) {
      arr[i] = s->data[i];
   }
}

//오름차순 정렬 함수
void Ascendingorder(int*arr, int n) {
   //스택을 두 개 만들고 초기화
   StackType s, s2; 
   Stackinit(&s, n);
   Stackinit(&s2, n);
   
   put_to_stack(arr, &s, n); //arr배열에 있는 원소들을 s스택에 저장
   
   //스택 s가 공백상태일 때까지 반복
   while ((&s)->top != -1) {
      int com = pop((&s));//스택 s에 가장 나중 값을 com에 저장
          while (1) {
            if(com >= (&s2)->data[(&s2)->top] || is_empty(&s2)){
               push((&s2), com);//스택 s2의 나중값(com)을 스택 s2에 저장
               break;//반복문 종료
            }
            else if (com < (&s2)->data[(&s2)->top]) {
               push((&s), pop((&s2)));//스택 s2의 나중값을 스택 s에 저장 (더 작은 값을 먼저 넣기 위해서)
            }
            //만약 스택 s2가 공백상태가 아니고 스택 s의 나중값(com)이 스택 s2의 나중값보다 작거나 같으면
          }      
   }
   put_to_array(arr, &s2);//정렬된 스택의 요소들을 배열에 저장
}

//내림차순 정렬 함수
void Desendingorder(int* arr, int n) {
   //스택을 두 개 만들고 초기화
   StackType s, s2;
   Stackinit(&s, n);
   Stackinit(&s2, n);

   put_to_stack(arr, &s, n); //arr배열에 있는 원소들을 s스택에 저장

   //스택 s가 공백상태일 때까지 반복
   while ((&s)->top != -1) {
      int com = pop((&s));//스택 s에 가장 나중 값을 com에 저장
          while (1) {
            if(com <= (&s2)->data[(&s2)->top] || is_empty(&s2)){
               push((&s2), com);//스택 s2의 나중값(com)을 스택 s2에 저장
               break;//반복문 종료
            }
            else if (com > (&s2)->data[(&s2)->top]) {
               push((&s), pop((&s2)));//스택 s2의 나중값을 스택 s에 저장 (더 작은 값을 먼저 넣기 위해서)
            }
            //만약 스택 s2가 공백상태가 아니고 스택 s의 나중값(com)이 스택 s2의 나중값보다 작거나 같으면
          }      
   }
   put_to_array(arr, &s2);//정렬된 스택의 요소들을 배열에 저장
}

//배열 출력 함수
void printArray(int *arr, int n) {
   //배열의 크기, 즉 n번 반복
   for (int i = 0; i < n; i++) {
      printf("%d  ", arr[i]);
   }
   printf("\n");
}

//메인 함수
int main() {
   srand(time(NULL)); //난수 생성
   int n;//사용자에게 입력 받는 변수
   printf("숫자 n을 입력하시오(10 ~ 100): ");
   scanf("%d", &n);//입력
   int* array = (int*)malloc(n * sizeof(int)); //n크기로 배열 동적할당
   //난수를 배열에 저장
   for (int i = 0;i < n;i++) {
      array[i] = rand() % 1000;
   }

   //정렬 전 배열 출력
   printf("정렬 전 : \n");
   printArray(array, n);
   printf("\n");

   //오름차순 정렬 후 출력
   Ascendingorder(array, n);
   printf("오름차순 정렬 : \n");
   printArray(array,n);
   printf("\n");

   //내림차순 정렬 후 출력
   Desendingorder(array, n);
   printf("내림차순 정렬 : \n");
   printArray(array, n);
   
   free(array);//메모리 해제
   return 0;
}