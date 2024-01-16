
# *21-1*

동기 입출력 & 비동기 입출력 이해

![[Pasted image 20240111030745.png]]



![[Pasted image 20240111031208.png]]

동기 Notification
반환을 통한 상태 확인을 수행한다.

비동기 Notification
직접 호출을 통한 상태 확인을 수행한다.



# *21-2*

WSAEventSelect함수와 Notification
![[Pasted image 20240111031432.png]]
WSAEventSelect : 상태 변화가 발생하면 모드를 변경한다.

manual-reset모드 Event 오브젝트의 또 다른 생성 방법
![[Pasted image 20240111031755.png]]


![[Pasted image 20240111031927.png]]


사용 코드
![[Pasted image 20240111032229.png]]
1. 원하는 타이밍에 WSAWaitForMultipleEvents를 호출한다.
2. hEventArray배열에서 numOfsock 갯수만큼의 핸들을 검사 실시
3. 그리고 WSA_INFINITE를 설정하여 무한대로 검사한다.
4. startIdx에 변화가 있는 인덱스 중 제일 첫번째 인덱스를 저장한다.
5. 저장된 인덱스를 바탕으로 반복문을 실행한다.

*오토 리셋 모드가 아닌 manual-reset모드인 이유는 WSAWaitForMultipleEvents함수가 반환이 되면 오토 리셋 모드에 경우 non-signaled로 바뀌어 반복문에서 확인이 불가하다.*

이벤트 종류의 구분을 위한 함수
![[Pasted image 20240111033115.png]]


각 이벤트 종류 별로 구분
![[Pasted image 20240111033438.png]]
