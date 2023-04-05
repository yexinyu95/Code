# 顺序
- 数学分析、线性代数、概率统计
- 普通、分式、根式、矩阵

# limits

1 $\lim\limits_{n \to \infty}{a}_{n} = a$

1.1 ${a}_{n} \to a$

2 $\lim\limits_{\substack{x \to \infty\\ y\to\infty \\ z\to\infty}}x_n$

3 $\lim\limits_{x \to {x}_{0}^{+}} f(x)$

4 $\lim\limits_{x \to 0} \dfrac {\sin x} {x} = 1$

5 $f(x) = \begin{cases}  g(x) & x>0 \\ h(x) & x<0 \end{cases}$

6 \Leftrightarrow  

# Differentiation
- 普通

1 $\lim\limits_{x \to x_0} f'(x) = \phi'(x)$

- 分式

2 $\lim\limits_{n \to \infty} \dfrac {1}{n+k} = \dfrac {1}{n}$

3 $\phi'(y_0) = \dfrac1 {f'(x_0)} ≠ \dfrac1 {f'(y_0)}$

4 $f'(x_0) =\lim\limits_{x \to x_0^-} \dfrac{f(x_0 + \Delta x) -f(x_0)} {\Delta x}$

5 $\dfrac{f(x) -f(x_0)} {x-x_0} < f(\dfrac{x_1 + x_2} 2)$

5.1 $\vec{X}$ + $\vec{0}$

6 $\dfrac{\partial^2 z} {\partial x \partial y}$

7 $\dfrac{\partial^2 f} {\partial x_1 \partial x_2}$

8 $\nabla \dfrac{\partial f} {\partial x_1}$

9 $\sqrt[n] {(x_1 + x_2)}$


10 $e^{-\dfrac{(x- \mu) ^{f(x)}} {2\sigma ^2}}$

11 ${e}^{\pm \infty} = e^{g(x)lnf(x)}$


# integral
- 普通

1 $|\int _{a}^{b}f(x) dx| ≤ \int _{a}^{b} |f(x)| dx$

2 $\int f(x,y) dx = F_x(x,y) + g(y)$

3 $\iint_{xy} f(x,y) d{\sigma} = \iint_{yx} f(y,x) d{\sigma}$

4 $\iiint f(x,y,z) d\sigma$

- 分式

5 $\lim\limits_{n \to \infty} \sum\limits_{i=1}^n \dfrac{b-a} n f(\xi _i) = \int _{a}^{b}f(x) dx$


# series
- 普通

1 $\sum\limits_{i=1}^n a_n$

2 $\sum\limits_{i=1}^n a_nx^n / a_n(x-x_0)^n$

3 $\lim\limits_{n \to \infty} S_{2n} - S_n = 0$


# lineal algebra
- matrix

2 x 2

$\begin{vmatrix}y_{1} & y_{2} \\y'_{1} & y'_{2} \\\end{vmatrix}$

${\begin{pmatrix} A_{(m*m)} & B \\ C & B_{(n*n)}  \\ \end{pmatrix}}^{-1}$

$\begin{cases}  F_{1}(x_{1}, x_{2},\cdots,  x_{n}) = 0 \\ F_{2}(x_{1}, x_{2},\cdots,  x_{n}) = 0  \\ \vdots \\ F_{m}(x_{1}, x_{2},\cdots,  x_{n}) = 0\end{cases}$

$\begin{cases}  a_{11}x_{1} + a_{12}x_{2} + \cdots +a_{1n}x_{n} = b_{1} \\   a_{21}x_{1} + a_{22}x_{2} + \cdots + a_{2n}x_{n} =b_{2} \end{cases}$

3 x 3

$\begin{pmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \\\end{pmatrix}$

4 x 4

$\begin{pmatrix} \lambda_{1} & & & \\ & \lambda_{2} & & \\ & &\ddots & \\ & & &\lambda_{n} \\ \end{pmatrix}$

$\begin{pmatrix} a_{11} & a_{12} & a_{13} & a_{14} \\ a_{21} & a_{22} & a_{23} & a_{24} \\ \cdots &  \\ a_{41} & a_{42} & a_{43} & a_{44} \\\end{pmatrix}$

$\begin{pmatrix} z_{1}^{2} & z_{1}z_{2} & \cdots & z_{1}z_{n} \\z_{2}z_{1} & z_{2}^{2} & \cdots & z_{2}z_{n} \\ \vdots & \vdots & & \vdots \\ z_{1}z_{2} & z_{1}z_{2} & \cdots & z_{n}^{2} \\ \end{pmatrix}$


5 x 5

$\begin{pmatrix} 1 & 1 & 1 & \cdots & 1 \\ a_1 & a_2 & a_3 & \cdots & a_n \\ a_1^2 & a_2^2 & a_3^2 & \cdots & a_n^2 \\ \vdots & \vdots & \vdots & & \vdots \\ a_1^n & a_2^n & a_3^n & \cdots & a_n^n \\ \end{pmatrix}$



- vector

$\begin{pmatrix}x_{1} & x_{2} & \cdots & x_{n} \end{pmatrix}$

$\begin{pmatrix} Y_{1} \\ Y_{2} \\ \vdots \\ Y_{n} \end{pmatrix}$

8.1 $x_{1}, x_{2},\cdots, x_{n}$

8.2 $X_{1}, X_{2},\cdots, X_{n}$

8.3 $\alpha_{1}, \alpha_{2},\cdots, \alpha_{r}$

$\begin{pmatrix} \alpha_1 & \alpha_2 & \cdots & \alpha_n \\ &  &  &  \\  & & &  \\  &  &  &  \\ \end{pmatrix}$

$\begin{pmatrix} \alpha_{1}^{T} & &  & \\\alpha_{2}^{T} & & &  \\ \vdots & & &  \\ \alpha_{n}^{T} & & &  \\ \end{pmatrix}$

$\begin{pmatrix} \alpha_{1}^{T}\alpha_{1} & \alpha_{1}^{T}\alpha_{2} & \cdots & \alpha_{1}^{T}\alpha_{n} \\\alpha_{2}^{T}\alpha_{1} & \alpha_{2}^{T}\alpha_{2} & \cdots & \alpha_{2}^{T}\alpha_{n} \\ \vdots & \vdots & & \vdots \\ \alpha_{n}^{T}\alpha_{1} & \alpha_{n}^{T}\alpha_{2} & \cdots & \alpha_{n}^{T}\alpha_{n} \\ \end{pmatrix}$

- sheet

3.1 
$\begin{array}{c|c}
\hline p & \lnot p\\
\hline 0 & 1      \\
       1 & 0      \\ 
\hline \end{array}$

3.2
$\begin{array}{c|c|c|c|c} 
\hline  p & q & p \Rightarrow q & q \Rightarrow p & p \Leftrightarrow q \\ \hline 0 & 1 & 1 & 0 & 0 \\ 1 & 1 & 1 & 1 & 1\\ 0 & 0 & 1 & 1 & 1 \\ 1 & 0 & 0 & 1 & 0\\  \hline \end{array}$








- 其他

10 $\sum \limits _{i= 1}^{n}\lambda_{i} =  \sum  \limits _{i = 1}^{n}a_{ii}$

11 $\prod \limits _{i = 1}^{n}\lambda_{i}= |A|$ 

# possibility

1 $P[(x_1 \leq k_1) \cup (x_2 \geq k_2)]$

1.1 $A\cap B = \varnothing$

2 $\overline{A\cup B}=\bar{A}\cap \bar{B}$   

2.1 $\lim\limits_{n \to \infty}A_{n}  = \mathop{\cup}\limits_{n =1}^{\infty}A_n = \sum\limits_{n =1}^{\infty} P(A_n)$，

2.2 $\mathop{\cup}\limits_{i =1}^{n}A_i = \sum\limits_{i =1}^{n} P(A_i)$，

2.3 $\overline {X} \stackrel{P} {\rightarrow} \mu$

3 ${n \choose x}$

4 $P_\theta (\theta \in [L(X), U(X)])$

5 $P_\theta (X \in [U^{-1}(\theta), L^{-1}(\theta)])$

6 $X \sim {\chi}^{2}(2\alpha)$

7 $(X,Y) \sim N(\mu_{1},\mu_{2},\sigma_{1}^{2},\sigma_{2}^{2},\rho)$

8 $\int _{-\infty}^{+\infty}\dfrac{1}{\sqrt{2\pi}\sigma}e^{-\dfrac{\left(x- \mu \right) ^{2}}{2\sigma ^{2}}} dx$

9 $\operatorname{Var}[X \pm Y] = \operatorname{Var}X + \operatorname{Var}Y \pm 2\operatorname{Cov}[X, Y]$

10 $\overline {X} =  \dfrac{X_{1} + X_{2} +\cdots+ X_{n}}{n} = \dfrac{1}{n}\sum \limits _{i= 1}^{n} {X}_{i}$

11 ${S}^{2} = \dfrac{1}{n - 1}\sum \limits _{i= 1}^{n}{({X}_{i} - \overline {X})}^{2}$

12 $\dfrac{L(\vec{\theta}|\vec{x}_{1})}{L(\vec{\theta}|\vec{x}_{2})}$

13 $\rho = \dfrac{\sigma_{ij}}{\sqrt{\sigma_{ii}}{\sqrt{\sigma_{jj}}}}$，