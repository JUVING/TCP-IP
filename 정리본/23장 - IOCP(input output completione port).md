
# *23-1*

하나의 쓰레드가 여려 개의 작업을 한번에 수행한다.

IOCP는 입출력 완료 포트(Input/Output Completion Port)의 약자로 Windows에서 비동기 I/O 작업을 효율적으로 처리하기 위해 사용되는 메커니즘입니다. 각 연결에 대한 스레드를 생성할 필요 없이 여러 동시 연결을 관리하기 위해 네트워크 프로그래밍에 일반적으로 사용됩니다.

iocp는 성능을 위하여 간결히 작성한 코드이다.

overlapped IO 모델에서 IOCP의 모델로
overlapped IO 모델의 문제점
1. 넌 - 블로킹 모드의 accept함수와 alertable wait상태로의 진입을 위한 sleepEx함수가 번갈아 가면 반복 호출되는 것은 성능에 영향을 미칠 수 있다.

overlapped IO 모델이 지니는 문제점의 해결책
1. accept함수의 호출은 main 쓰레드가(main 함수 내에서) 처리하도록 하고
2. 별도의 쓰레드를 추가로 하나 생성해서 클라이언트와의 입출력을 담당하게 한다.
	    (I/O를 담당하는 쓰레드를 생성한다.)


# *23-2*

IOCP 순서
1. 연결요청 수락 -> (소켓이 생성된다.)
2.  소켓과 IOCP오브젝트와 연결한다.  -> (소켓을 대상으로 IO를 진행하여 완료하면 IOCP에 저장된다.)
3. 임의에 쓰레드가 IOCP에 완료된 작업이 있나 요청한다. -> (있으면 완료 이후에 작업을 진행한다.)

IOCP에서의 IO의 완료 확인
IOCP 기본 모델 :
1. IOCP에서는 완료된 IO의 정보가 Completion Port 오브젝트라는 커널 오브젝트에 등록된다.

IOCP의 기본 조건
1. Completion Port 오브젝트의 생성 (직접 생성해야 한다.)
2. Completion Port 오브젝트와 IO의 완료를 등록할 소켓과의 연결

createCompletionPort함수의 두 가지 기능
![[Pasted image 20240115002154.png]]


Completion Port의 완료된 IO 확인
![[Pasted image 20240115002628.png]]

GetQueued~함수 호출과 데이터의 전달관계
![[Pasted image 20240115002833.png]]
