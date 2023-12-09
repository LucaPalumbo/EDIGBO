# Energy dissipation in galactic bullet orbit
The aim of this project is to understand the behaviour of a relativistic bullet-star that enters in a galaxy.
To do that we analyze:
## 2StarScattering
We shoot one star to another and measure how much energy is trasfered to the target.
### Expected energy loss
Let's consider the collision *rapid* (as in the Bohr calculation). With this hypothesis we can estimate the energy loss in a single collision by evaluating this integral

$ |\Delta p_y| = \int_{-\infty}^{+\infty}F_y dt = \int_{-\infty}^{+\infty} -\frac{GM_1M_2 \sin(\theta)}{r^2}dt $

Remembering that $r^2 = b^2 +(vt)^2$ and $r\sin(\theta) = b$ we obtain

$ |\Delta p_y| = -GM_1M_2b \int_{-\infty}^{+\infty} \frac{1}{(v^2t^2+b^2)^{3/2}}dt $

that yields

$ |\Delta p_y| = -\frac{2GM_1M_2}{bv} $