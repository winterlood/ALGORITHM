# 집구하기

[문제 링크](https://www.acmicpc.net/problem/13911)

## 풀이

Let the **macdonalds** number is  'm'

and let the **starbucks** nodes number is 'n'

in First time i think m*n time run dijkstra...

but  m <= 10000, n<= 10000.  thus time limits occured...

so make the super node

아 영어로 쓰려니 넘 힘들다 고로 한글로 쓰도록 하겠다.

결론은 스타벅스들을 모아놓는 슈퍼노드 한개와 (슈퍼스타 노드라고 부르자)

맥도날드들을 모아놓는 슈퍼노드 한개 (슈퍼맥도 노드라고 부름)

를 만들고 두번의 다익스트라를 통해 문제를 해결 할 수있다.

그럼 어떻게 하지 ??...


