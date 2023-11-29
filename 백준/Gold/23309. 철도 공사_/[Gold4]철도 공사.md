## [Gold4] 23309. 철도 공사
<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/19a8adca-5e60-48c7-91f2-b3a285366a5d/-/preview/" style="width: 417px; height: 350px;" /><br />
[그림] 2호선 노선도</p>

<p>연세대학교가 위치한 신촌역이&nbsp;속한 2호선은 그림과 같이 $N$개의 역이 원형으로 연결되어 있다. 각 역은&nbsp;고유 번호가 할당돼 있으며&nbsp;역들의 고유 번호는 서로 다르다. 그리고 특정 역의 다음 역은 시계 방향으로 인접한&nbsp;역을 의미하고, 이전 역은 반시계 방향으로 인접한 역을 의미한다.</p>

<p>2호선은 지하철 노선들 중 유일한 흑자 노선이다. 때문에 2호선 공사 자금이 넉넉하기에 $M$번의 공사를 거치려고 한다. 각 공사는 다음 4가지 중&nbsp;하나를 시행한다.</p>

<ul>
	<li>고유 번호 $i$를 가진&nbsp;역의 다음 역의 고유 번호를 출력하고,&nbsp;그 사이에 고유 번호 $j$인 역을 설립한다.</li>
	<li>고유 번호 $i$를 가진&nbsp;역의&nbsp;이전&nbsp;역의 고유 번호를 출력하고, 그 사이에 고유 번호 $j$인 역을 설립한다.</li>
	<li>고유 번호 $i$를 가진&nbsp;역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력한다.</li>
	<li>고유 번호 $i$를 가진&nbsp;역의 이전&nbsp;역을 폐쇄하고 그 역의 고유 번호를 출력한다.</li>
</ul>

<p>이 때, 이미 설립한 역은 다시 설립하지 않으며 폐쇄한 역은 다시 설립될 수 있다. 그리고 폐쇄 작업은 현재 설립된 역이 $2$개 이상일 때만 들어온다.</p>

<p>2호선을 공사하는 프로그램을 만들어보자.</p>

</div>
</section>
</div>
            <div class="col-md-12">
  <section id="input"  class="problem-section">
  <div class="headline">
  <h2>입력</h2>
  </div>
  <div id="problem_input" class="problem-text">
  <p>첫 번째 줄에&nbsp;공사를 시작하기 이전에 있는&nbsp;역의 개수를 나타내는 양의 정수 $N$과 공사 횟수를 나타내는 양의 정수 $M$이 주어진다. ($1 \le N \le 500\,000$,&nbsp;$1 \le M \le 1\,500\,000$)</p>

<p>두 번째 줄에는 공사를 시작하기 이전에 있는 역의 고유 번호를 시계 방향 순서대로 주어진다. 같은 고유 번호를 가진 역은 주어지지 않는다.</p>

<p>이후 $M$개의 줄에 걸쳐서 공사에 대한 정보를 다음과 같이 주어진다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>BN</code></span> $i$ $j$ :&nbsp;고유 번호 $i$를 가진&nbsp;역의 다음 역의 고유 번호를 출력하고,&nbsp;그 사이에 고유 번호 $j$인 역을 설립한다.</li>
	<li><span style="color:#e74c3c;"><code>BP</code></span>&nbsp;$i$ $j$ :&nbsp;고유 번호 $i$를 가진&nbsp;역의 이전&nbsp;역의 고유 번호를 출력하고,&nbsp;그 사이에 고유 번호 $j$인 역을 설립한다.</li>
	<li><span style="color:#e74c3c;"><code>CN</code></span> $i$&nbsp;: 고유 번호 $i$를 가진&nbsp;역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력한다.</li>
	<li><span style="color:#e74c3c;"><code>CP</code></span>&nbsp;$i$&nbsp;:&nbsp;고유 번호 $i$를 가진&nbsp;역의 이전&nbsp;역을 폐쇄하고 그 역의 고유 번호를 출력한다.</li>
</ul>

<p>입력으로 들어오는 모든 역의 고유 번호는 $1$ 이상 $1\,000\,000$ 이하의 양의 정수다.&nbsp;폐쇄 작업은&nbsp;현재 설립된 역이 $2$개 이상일 때만 들어오며, 이미 설립된 역은 또&nbsp;설립될 수 없지만&nbsp;폐쇄된 역은 다시 설립될 수 있다.</p>
