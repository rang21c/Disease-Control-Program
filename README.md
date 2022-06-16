# Disease-control-program

본 프로젝트에서는 이진 탐색 트리(Binary Search Tree, BST)와 큐(Queue), 힙(Heap)을 이용하여 질병 관리 프로그램을 구현한다. 이 프로그램은 질병 의심 환자 데이터 이름, 체온, 기침 여부, 지역을 받아 Queue에 구축하며, 해당 Queue를 Patient_Queue라 부른다. Queue에서 pop 명령어를 실행하면 BST 구조에 저장된다. BST는 Location_BST, Patient_BST 두 종류로 구성된다. Location_BST는 지역 정보를 담고 있는 BST이고, Patient_BST는 각 Location_BST의 노드마다 하나씩 연결된 BST 이다. Patient_Queue에서 pop된 환자 데이터는 환자의 지역에 해당하는 노드
에 속한 Patient_BST에 삽입되며, 이때, 질병 여부를 검증하여 양성 혹은 음성 여부를 ‘+’, ‘-’로 표기하여 저장한다. BST에서 pop 명령어를 실행하면 Location_MaxHeap 이라는 Heap 구조에 저장되며, 각 노드는 지역과 지역에 해당하는 환자 수를 기준으로 정렬된다.

![image](https://user-images.githubusercontent.com/33370179/174055369-dbb26f18-4530-4d3f-9cd2-a2008a47cb03.png)

### 1. Patient_Queue
- 주어진 data.txt에 저장된 데이터를 이용하여 구축한다. Queue의 자료구조에 따라 저장되는 순서대로 방출된다. Queue에는 data.txt에 첫 번째 줄부터 마지막 줄까지 순서대로 저장된다. 
- 프로그램 구현 시 Queue는 <queue> 라이브러리에서 제공하는 STL을 이용한다. 
- Queue에 저장되는 데이터는 PatientNode class로 선언되어 있으며 멤버 변수로는 환자이름, 체온, 기침 여부, 지역을 갖는다. - 이름 정보는 항상 고유하며, 중복으로 입력되는 경우는 없다고 가정한다.

![image](https://user-images.githubusercontent.com/33370179/174055491-486062f7-a6bd-4044-9105-6e1c25b709a9.png)

### 2. Location_BST
- Location_BST는 초기에 한 번 구축되며, 그 후로 노드 추가 혹은 삭제가 일어나지 않는다.
- Location_BST의 구조는 그림 3과 동일하게 구성되어야 한다. 즉 반드시 Gwangju, Daegu, Seoul, Busan, Daejeon, Incheon, Ulsan 순으로 추가한다.
- 지역 이름은 항상 첫 글자만 대문자로 표기하며 그렇지 않은 경우의 입력은 없다고 가정한다. 
- Patient_Queue에서 방출된 데이터의 지역 정보를 확인하여 해당 지역의 노드에 속한 Patient_BST에 삽입한다. 
- 예를 들어, {tom, 37.2, Y, Seoul}와 같이 구성된 환자 데이터는 Location_BST의 Seoul 노드에 속한 Patient_BST에 삽입한다. 
- Location_BST에 저장되는 데이터는 LocationNode class로 선언되어 있으며 멤버 변수로는 지역, Patient_BST 포인터를 갖는다.
  
![image](https://user-images.githubusercontent.com/33370179/174055582-59869f1e-6dda-47b8-a6b3-93b63b156fea.png)

### 3. Patient_BST
- Patient_BST는 그림 4와 같이 Locaton_BST의 각 노드에 속한 BST이다. 
- Location_BST에는 Patient_BST의 root 노드의 주소값만 저장하고 있으며, 초기값은 null이다.
- Patient_Queue에서 방출된 데이터를 삽입하며, 체온과 기침 여부 데이터를 통하여 양성, 음성을 판단한다. 
* 체온은 37.5도 이상이며 기침 여부가 Y일 경우 양성으로 판단하여 ‘+’를 표기한다. 그 이외의 경우는 모두 음성으로 판단하여 ‘-’를 표기한다. 
- 저장되는 데이터는 이름, 양성/음성 정보이다. (온도, 기침 여부 등 데이터 표기 제외) 
- Patient_BST에서 지원하는 연산은 삽입, 삭제, 탐색(중위 순회, 후위 순회, 전위 순회, 레벨 순회)이다. 각 연산에 대해서는 Functional Requirements에서 자세히 설명한다. 
- Patient_BST에 저장되는 데이터는 PatientBSTNode class에 선언되며, 멤버 변수로 환자이름, 양성 음성 여부를 갖고 있다. 
- Patient_BST의 자료구조 정보는 PatientBST class에 선언되며, 멤버 변수로 root 정보를 가지고 있으며 멤버 함수로 삽입, 삭제, 탐색 등 요구되는 연산을 위한 함수를 갖고 있다.
- Patient_BST에서 사용되는 BST를 연결하는 규칙은 다음과 같다.
  
![image](https://user-images.githubusercontent.com/33370179/174055765-5d464e96-3eab-443a-91bb-31d512256f2f.png)

※ BST 연결 규칙
① 부모 노드보다 환자 이름의 사전적 순서가 작은 노드는 왼쪽, 큰 노드는 오른쪽 서브 트리에 반
드시 위치한다. ② 노드를 제거할 때, 양쪽 자식 노드가 모두 존재할 경우에는 왼쪽 자식 노드 중 가장 큰 노드를 
제거되는 노드 위치로 이동시킨다. 

  
### 4. Location_MaxHeap
- Location_MaxHeap의 Heap는 그림 5와 같이 지역에 해당하는 환자 수를 기준으로 정렬된다. 
- BST에서 방출된 데이터를 삽입하며, max를 결정하는 기준은 지역에 속한 환자의 수이다. 다시 말해, BST에서 가장 많이 방출된 지역이 root에 오게 된다. 
- BST에서 방출 연산이 일어날 때마다 Heap을 재정렬한다. 
- Heap을 재정렬할 때, 비교하는 노드의 환자 수가 추가된 노드보다 크거나 같은 경우에 정렬을 완료한다. 
- Loction_MaxHeap에서는 삽입 연산만 이뤄진다. 
- Loction_MaxHeap에 저장되는 데이터는 LocationHeapNode class로 선언되어 있으며 멤버 변수로는 지역에 속한 환자 수, 지역 이름을 갖고 있다.

![image](https://user-images.githubusercontent.com/33370179/174056267-2ae996c1-74dc-461c-a5c1-bd3aa3c5dfcf.png)
