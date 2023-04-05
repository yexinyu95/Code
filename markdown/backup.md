
- 备用

**6.基本导数与微分表**
(1) $y=c$（常数）       ${y}'=0$          $dy=0$
(2) $y={{x}^{\alpha }}$($\alpha $为实数)    ${y}'=\alpha {{x}^{\alpha -1}}$      $dy=\alpha {{x}^{\alpha -1}}dx$
(3) $y={{a}^{x}}$      ${y}'={{a}^{x}}\ln a$         $dy={{a}^{x}}\ln adx$
  特例:   $({{{e}}^{x}}{)}'={{{e}}^{x}}$             $d({{{e}}^{x}})={{{e}}^{x}}dx$

(4) $y={{\log }_{a}}x$   ${y}'=\frac{1}{x\ln a}$           

$dy=\frac{1}{x\ln a}dx$
  特例:$y=\ln x$                      $(\ln x{)}'=\frac{1}{x}$       $d(\ln x)=\frac{1}{x}dx$

(5) $y=\sin x$         

${y}'=\cos x$        $d(\sin x)=\cos xdx$

(6) $y=\cos x$      

${y}'=-\sin x$       $d(\cos x)=-\sin xdx$

(7) $y=\tan x$  

${y}'=\frac{1}{{{\cos }^{2}}x}={{\sec }^{2}}x$  $d(\tan x)={{\sec }^{2}}xdx$
(8) $y=\cot x$ ${y}'=-\frac{1}{{{\sin }^{2}}x}=-{{\csc }^{2}}x$  $d(\cot x)=-{{\csc }^{2}}xdx$
(9) $y=\sec x$ ${y}'=\sec x\tan x$     

 $d(\sec x)=\sec x\tan xdx$
(10) $y=\csc x$ ${y}'=-\csc x\cot x$    

$d(\csc x)=-\csc x\cot xdx$
(11) $y=\arcsin x$  

${y}'=\frac{1}{\sqrt{1-{{x}^{2}}}}$   

$d(\arcsin x)=\frac{1}{\sqrt{1-{{x}^{2}}}}dx$
(12) $y=\arccos x$ 

${y}'=-\frac{1}{\sqrt{1-{{x}^{2}}}}$     $d(\arccos x)=-\frac{1}{\sqrt{1-{{x}^{2}}}}dx$

(13) $y=\arctan x$ 

${y}'=\frac{1}{1+{{x}^{2}}}$     $d(\arctan x)=\frac{1}{1+{{x}^{2}}}dx$

(14) $y=\operatorname{arc}\cot x$      

${y}'=-\frac{1}{1+{{x}^{2}}}$   

$d(\operatorname{arc}\cot x)=-\frac{1}{1+{{x}^{2}}}dx$
(15) $y=shx$    

${y}'=chx$       $d(shx)=chxdx$

(16) $y=chx$    

${y}'=shx$       $d(chx)=shxdx$


**8.常用高阶导数公式**

（1）$({{a}^{x}}){{\,}^{(n)}}={{a}^{x}}{{\ln }^{n}}a\quad (a>{0})\quad \quad ({{{e}}^{x}}){{\,}^{(n)}}={e}{{\,}^{x}}$
（2）$(\sin kx{)}{{\,}^{(n)}}={{k}^{n}}\sin (kx+n\cdot \frac{\pi }{{2}})$
（3）$(\cos kx{)}{{\,}^{(n)}}={{k}^{n}}\cos (kx+n\cdot \frac{\pi }{{2}})$
（4）$({{x}^{m}}){{\,}^{(n)}}=m(m-1)\cdots (m-n+1){{x}^{m-n}}$
（5）$(\ln x){{\,}^{(n)}}={{(-{1})}^{(n-{1})}}\frac{(n-{1})!}{{{x}^{n}}}$



**9.微分中值定理，泰勒公式**

**Th1:**(费马定理)

若函数$f(x)$满足条件：
(1)函数$f(x)$在${{x}_{0}}$的某邻域内有定义，并且在此邻域内恒有
$f(x)\le f({{x}_{0}})$或$f(x)\ge f({{x}_{0}})$,

(2) $f(x)$在${{x}_{0}}$处可导,则有 ${f}'({{x}_{0}})=0$

**Th2:**(罗尔定理) 

设函数$f(x)$满足条件：
(1)在闭区间$[a,b]$上连续；

(2)在$(a,b)$内可导；

(3)$f(a)=f(b)$；

则在$(a,b)$内一存在个$\xi $，使  ${f}'(\xi )=0$
**Th3:** (拉格朗日中值定理) 

设函数$f(x)$满足条件：
(1)在$[a,b]$上连续；

(2)在$(a,b)$内可导；

则在$(a,b)$内一存在个$\xi $，使  $\frac{f(b)-f(a)}{b-a}={f}'(\xi )$

**Th4:** (柯西中值定理)

 设函数$f(x)$，$g(x)$满足条件：
(1) 在$[a,b]$上连续；

(2) 在$(a,b)$内可导且${f}'(x)$，${g}'(x)$均存在，且${g}'(x)\ne 0$

则在$(a,b)$内存在一个$\xi $，使  $\frac{f(b)-f(a)}{g(b)-g(a)}=\frac{{f}'(\xi )}{{g}'(\xi )}$

**10.洛必达法则**
法则Ⅰ ($\frac{0}{0}$型)
设函数$f\left( x \right),g\left( x \right)$满足条件：
 $\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,f\left( x \right)=0,\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,g\left( x \right)=0$; 

$f\left( x \right),g\left( x \right)$在${{x}_{0}}$的邻域内可导，(在${{x}_{0}}$处可除外)且${g}'\left( x \right)\ne 0$;

$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}$存在(或$\infty $)。

则:
$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{f\left( x \right)}{g\left( x \right)}=\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}$。
法则${{I}'}$ ($\frac{0}{0}$型)设函数$f\left( x \right),g\left( x \right)$满足条件：
$\underset{x\to \infty }{\mathop{\lim }}\,f\left( x \right)=0,\underset{x\to \infty }{\mathop{\lim }}\,g\left( x \right)=0$;

存在一个$X>0$,当$\left| x \right|>X$时,$f\left( x \right),g\left( x \right)$可导,且${g}'\left( x \right)\ne 0$;$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}$存在(或$\infty $)。

则:
$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{f\left( x \right)}{g\left( x \right)}=\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}$
法则Ⅱ($\frac{\infty }{\infty }$型) 设函数$f\left( x \right),g\left( x \right)$满足条件：
$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,f\left( x \right)=\infty ,\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,g\left( x \right)=\infty $;   $f\left( x \right),g\left( x \right)$在${{x}_{0}}$ 的邻域内可导(在${{x}_{0}}$处可除外)且${g}'\left( x \right)\ne 0$;$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}$存在(或$\infty $)。则
$\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{f\left( x \right)}{g\left( x \right)}=\underset{x\to {{x}_{0}}}{\mathop{\lim }}\,\frac{{f}'\left( x \right)}{{g}'\left( x \right)}.$同理法则${I{I}'}$($\frac{\infty }{\infty }$型)仿法则${{I}'}$可写出。

**11.泰勒公式**

设函数$f(x)$在点${{x}_{0}}$处的某邻域内具有$n+1$阶导数，则对该邻域内异于${{x}_{0}}$的任意点$x$，在${{x}_{0}}$与$x$之间至少存在
一个$\xi $，使得：
$f(x)=f({{x}_{0}})+{f}'({{x}_{0}})(x-{{x}_{0}})+\frac{1}{2!}{f}''({{x}_{0}}){{(x-{{x}_{0}})}^{2}}+\cdots $ 
$+\frac{{{f}^{(n)}}({{x}_{0}})}{n!}{{(x-{{x}_{0}})}^{n}}+{{R}_{n}}(x)$
 其中 ${{R}_{n}}(x)=\frac{{{f}^{(n+1)}}(\xi )}{(n+1)!}{{(x-{{x}_{0}})}^{n+1}}$称为$f(x)$在点${{x}_{0}}$处的$n$阶泰勒余项。

令${{x}_{0}}=0$，则$n$阶泰勒公式
$f(x)=f(0)+{f}'(0)x+\frac{1}{2!}{f}''(0){{x}^{2}}+\cdots +\frac{{{f}^{(n)}}(0)}{n!}{{x}^{n}}+{{R}_{n}}(x)$……(1)
其中 ${{R}_{n}}(x)=\frac{{{f}^{(n+1)}}(\xi )}{(n+1)!}{{x}^{n+1}}$，$\xi $在0与$x$之间.(1)式称为麦克劳林公式


**常用五种函数在${{x}_{0}}=0$处的泰勒公式**

(1) ${{{e}}^{x}}=1+x+\frac{1}{2!}{{x}^{2}}+\cdots +\frac{1}{n!}{{x}^{n}}+\frac{{{x}^{n+1}}}{(n+1)!}{{e}^{\xi }}$ 

或 $=1+x+\frac{1}{2!}{{x}^{2}}+\cdots +\frac{1}{n!}{{x}^{n}}+o({{x}^{n}})$

(2) $\sin x=x-\frac{1}{3!}{{x}^{3}}+\cdots +\frac{{{x}^{n}}}{n!}\sin \frac{n\pi }{2}+\frac{{{x}^{n+1}}}{(n+1)!}\sin (\xi +\frac{n+1}{2}\pi )$

或  $=x-\frac{1}{3!}{{x}^{3}}+\cdots +\frac{{{x}^{n}}}{n!}\sin \frac{n\pi }{2}+o({{x}^{n}})$

(3) $\cos x=1-\frac{1}{2!}{{x}^{2}}+\cdots +\frac{{{x}^{n}}}{n!}\cos \frac{n\pi }{2}+\frac{{{x}^{n+1}}}{(n+1)!}\cos (\xi +\frac{n+1}{2}\pi )$

或   $=1-\frac{1}{2!}{{x}^{2}}+\cdots +\frac{{{x}^{n}}}{n!}\cos \frac{n\pi }{2}+o({{x}^{n}})$

(4) $\ln (1+x)=x-\frac{1}{2}{{x}^{2}}+\frac{1}{3}{{x}^{3}}-\cdots +{{(-1)}^{n-1}}\frac{{{x}^{n}}}{n}+\frac{{{(-1)}^{n}}{{x}^{n+1}}}{(n+1){{(1+\xi )}^{n+1}}}$

或      $=x-\frac{1}{2}{{x}^{2}}+\frac{1}{3}{{x}^{3}}-\cdots +{{(-1)}^{n-1}}\frac{{{x}^{n}}}{n}+o({{x}^{n}})$

(5) ${{(1+x)}^{m}}=1+mx+\frac{m(m-1)}{2!}{{x}^{2}}+\cdots +\frac{m(m-1)\cdots (m-n+1)}{n!}{{x}^{n}}$ 
$+\frac{m(m-1)\cdots (m-n+1)}{(n+1)!}{{x}^{n+1}}{{(1+\xi )}^{m-n-1}}$ 

或 ${{(1+x)}^{m}}=1+mx+\frac{m(m-1)}{2!}{{x}^{2}}+\cdots $ $+\frac{m(m-1)\cdots (m-n+1)}{n!}{{x}^{n}}+o({{x}^{n}})$



$\begin{vmatrix}
        {(kA)}^T = kA^{T} & {(kA)}^{-1} = k^{-1}A^{-1} & {(kA)}^{*} = k^{n-1}A^{*} & |kA| = k^{n}A \\        
        ({(A)^{T}})^{T} = A & ({(A)^{-1}})^{-1} = A & ({(A)^{*}})^{*} = {|A|}^{n-2} A &   \\        
        {(AB)}^{T} = {B}^{T}{A}^{T} & {(AB)}^{-1} = {B}^{-1}{A}^{-1} & {(AB)}^{*} \not = & {|AB|} = |BA| = |A| \cdot |B| \\        
        {(A + B)}^{T} = {A}^{T} + {B} ^ {T} & {(A + B)}^{-1} \not= & {(A + B)}^{*} \not= & {|A + B|} \not= \\
        {({A}^{T})}^{-1} = {({A}^{-1})}^{T} &  & {({A}^{*})}^{-1} = {({A}^{-1})}^{*} &  \\
         &  &{({A}^{*})}^{T} = {({A}^{T})}^{*}  &  \\
         |A| = |A^T| &|A^{-1}| = {(|A|)}^{-1}  &|A^{*}| = {|A|}^{n-1} &  \\
 \end{vmatrix}$


$\begin{vmatrix}kA & A^{k} & A^{-1} & A+kE &f(A)\ \  & A^{*} \\ k & {\lambda}^{k} & {\lambda}^{-1} & {\lambda}+k &f({\lambda})\ \  & \dfrac{|A|}{\lambda} \\ \alpha \\\end{vmatrix}$

$\begin{vmatrix}A^{T} &  & B = P^{-1}AP \\\lambda &  & \lambda \\ \lambda &  & P^{-1}\alpha  \end{vmatrix}$



$1 \leq r(A) \leq \min(m,n)$

$r(A) = 0 \leftrightarrow A = 0$

$r(A) = r(A^{T})$,$r(A) = r(kA)$

$r(PAQ) = r(A), r(PA) = r(A),r(AQ) = r(A)$

$r(P^{-1}AP) = r(A)$,$r(P^{T}AP) = r(A)$

$\max[r(A), r(B)] \leq r(A,B) \leq r(A) + r(B)$

$r(A + B) \leq r(A) + r(B) \leq r(AB) + n (A_{m*n}B_{n*s})$

$r(AB) \leq \min[r(A), r(B)]$

$AB = 0 \leftrightarrow r(A) + r(B) \leq n$

$\begin{vmatrix}r(A) = n &  & r(A^{*}) = n \\ r(A) = n-1 &  & r(A^{*}) = 1 \\ r(A) \leq n-1 &  & r(A^{*}) = 0 \\ \end{vmatrix}$


$r(A) = r(A^{T}A) (= r(A^{T}) = r(AA^{T}))$

$AX = B$,$r(A) = r(A,B)$



$P(A \cup B) = P(A)+P(B) - P(AB)   $
$P(A \cup B \cup C) = P(A) + P(B) +P(C) -P(AB)-P(AC)-P(BC)+P(ABC) $
$P(A-B) = P(A\bar{B}) = P(A)- P(AB) $
$P(AB) = P(A)P(B|A)$
$P(A) = \sum\limits_{i = 1}^{n}P(B_{i})P(A|B_{i})$
$P(A) = P(\bar{B})P(A|\bar{B}) + P(B)P(A|B)$

$P(B_{j}|A) = \dfrac{P{(AB_{j})}}{P(A)} = \dfrac{P(B_{j})P(A|B_{j})}{\sum\limits_{i = 1}^{n}P(B_{i})P(A|B_{i})} $

$P(B|A) = \dfrac{P{(AB)}}{P(A)} = \dfrac{P(B)P(A|B)}{P(\bar{B})P(A|\bar{B}) + P(B)P(A|B)}$





$p \lor q \equiv q \lor p$

$p \land q \equiv q \land p$

$(p \lor q) \lor r \equiv p \lor (q \lor r)$

$(p \land q) \land r \equiv p \land (q \land r)$

$p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$

$p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$

$p \lor (p \land q) \equiv p$

$p \land (p \lor q) \equiv p$


$p \rightarrow q \equiv \lnot p \lor q$

$p \rightarrow q \equiv \lnot q \rightarrow \lnot p$(逆否命题)

$p \lor  q \equiv \lnot p \rightarrow q$

$p \land q \equiv \lnot (p \rightarrow \lnot q)$

$\lnot (p \rightarrow q) \equiv p \land (\lnot q)$

$(p \rightarrow q) \land (p \rightarrow r) \equiv p \rightarrow (q \land r)$

$(p \rightarrow r) \land (q \rightarrow r) \equiv (p \lor q) \rightarrow r$

$(p \rightarrow q) \lor (p \rightarrow r) \equiv p \rightarrow (q \lor r)$

$(p \rightarrow r) \lor (q \rightarrow r) \equiv (p \land q) \rightarrow r$

$p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$（定义）

$p \leftrightarrow q \equiv \lnot p \leftrightarrow \lnot q$

$p \leftrightarrow q \equiv (p \land q) \lor (\lnot p \land \lnot q)$

$\lnot (p \leftrightarrow q) \equiv p \leftrightarrow \lnot q$


$((p \rightarrow q) \land \lnot q) \rightarrow \lnot p$

$((p \rightarrow q) \land (q \rightarrow r)) \rightarrow (p \rightarrow r)$

$((p \lor q) \land (\lnot q)) \rightarrow q$

$p \rightarrow (p \lor q)$

$(p \land q) \rightarrow p$

$((p \lor q) \land (\lnot p \lor r)) \rightarrow (q \lor r)$

