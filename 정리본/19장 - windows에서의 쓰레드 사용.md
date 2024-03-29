
# *19-1*

커널 오브젝트

커널 오브젝츠 요약 : *프로세스의 많은 정보를 담기 위하여 생성된 구조체 변수*이며 
*시스템 리소스에 따라 담는 데이터의 형태가 다르다.

운영 체제의 커널 개체는 실제로 프로세스, 스레드, 파일 및 기타 시스템 리소스와 같은 시스템 내의 다양한 엔터티를 나타내고 관리하는 데 사용되는 데이터 구조입니다. 이러한 구조에는 각 엔터티와 관련된 필수 정보 및 속성이 포함되어 있어 커널이 이를 효율적으로 관리하고 제어할 수 있습니다.

![[Pasted image 20240108015841.png]]

커널 오브젝트의 이해

운영체제가 만드는 리소스의 유형
1. 프로그램의 실행과 관련된 *프로스세와 쓰레드
2. 입출력의 도구가 되는 *소켓과 파일
3. 쓰레드간 동기화의 도구로 사용되는 *세마포어 뮤텍스

리소스와 커널 오브젝트의 관계
1. *리소스 관리*를 위해서 *운영체제가 만드는 데이터 블록이 커널 오브젝트*이다.
2. 커널 오브젝트에는 해당 *리소스의 정보가 저장되어* 있다.
3. *리소스의 종류*에 따라서 생성되는 *커널 오브젝트의 형태에도 차이*가 있다.

커널 오브젝트의 소유자
1. 커널 오브젝트의 *생성, 관리 및 소멸은 운영체제*가 담당한다.
2. 즉 커널 오브젝트의 소유자는 *운영체제*이다.


# *19-2*

프로세스는 쓰레드를 담는 상자

단일 쓰레드 모델
- 추가로 쓰레드를 생성하지 않는 모델의 프로그램

멀티 쓰레드 모델
- 프로그램 내에서 추가로 쓰레드를 생성하는 모델의 프로그램

쓰레드 생성 방법
![[Pasted image 20240109012523.png]]


![[Pasted image 20240109014828.png]]

![[Pasted image 20240109015118.png]]


# *19-3*


커널 오브젝트의 두 가지 상태
non - signled 상태
- 이벤트가 발생하지 않은 상태, *해당 리소스가 특정 상황에 이르지 않은 상태

signled 상태
- *이벤트가 발생한 상태, 해당 리소스가 특정상황*에 도달한 상태
(특정상황 : 쓰레드가 종료 되었을 떄)
