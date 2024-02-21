
# *22-1*

IO의 중첩

![[Pasted image 20240113034136.png]]

bloking & non-bloking
![[Pasted image 20240113034028.png]]


비동기 IO와 윈도우의 Overlapped IO의 비교
비동기 IO
1. IO의 비동기란 넌 블로킹(non-bloking)모드의 IO를 뜻한다.
2. IO가 비동기 방식으로 동작해야 IO를 중첩시킬 수 있다.
3. 윈도우의 Overlapped IO는 IO를 중첩시키는 입출력 모델이다.

Overlapped IO
1. Overlapped IO가 아니더라도 IO를 *중첩이 가능*하다.
2. Overlapped IO의 포커스는 IO가 아닌 *입출력의 완료(전송 상태) 확인방법에 있다.*


Overlapped IO의 적합한 소켓 생성
![[Pasted image 20240113034802.png]]

Overlapped IO를 진행하는 WSASend 함수
![[Pasted image 20240113034941.png]]

데이터 송수신 결과의 확인방법
![[Pasted image 20240113035620.png]]

Overlapped IO를 진행하는 WSARecv함수
![[Pasted image 20240113040342.png]]



# *22-2*

Overlapped IO상태 확인 방법
1. 이벤트 오브젝트 : WSASend(), SOCKET_ERROR
2. CR(컨플리션 루틴) : IO작동이 완료 되었을떄에 호출할 함수 등록

Event 오브젝트 기반의 send
![[Pasted image 20240113040918.png]]


WSAGetLastError
![[Pasted image 20240113041001.png]]
오류 발생 했을때 원인을 확인할떄 사용하며 오류 코드를 반환한다.

Completion Routine 사용하기

Completion Routine 이해
1. IO가 완료되었을때 호출되는 함수를 가리켜 completion Routine이라 한다.
2. IO가 완료되면 미리 등록된  completion Routine이 운영체제에 의해서 자동으로 호출된다.
3. completion Routine이 호출되기 위해서 해당 쓰레드가 *alertable wait상태에 놓여야 한다,
4. Alertable wait은 *운영체제가 전달하는 메시지의 수신이 가능한 상태 다시 말해서 특별한 일을 진행하지 않는 상태*를 뜻한다.

Alertable wait상태로의 진입에 사용되는 함수
1. WaitForSingleObjectEx
2. WaitForMultipleObjectsEx
3. WaitForMutipleEvents
4. sleepEx


Completion Routine 단점
CR을 사용해야 할때 알려줘야한다 : 
CR을 필요한 시기에 호출 해줘야 한다 그렇지 않으면 코드 진행 중 중요한 부분에서 CR로 요청한 함수로 넘어 가거나 코드 진행 중 CR이 호출 되어서 함수 실행 후 빠져 나오면 진행 중이 던 나뭐지를 진행하지 않는다.

Completione Routine의 예
![[Pasted image 20240113042141.png]]
