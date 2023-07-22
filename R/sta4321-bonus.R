#Jared Bumgardner (Bonus)
#note: CTRL+L clear console


###### BINOMIAL DISTRIBUTION ######
### Consider Y~bin(n=10, p=0.12) ###
n = 10
p = 0.12
print(paste("P(Y = 3) = ", dbinom(3, n, p)))

### Consider X~bin(n=15, p=0.5) ###
n = 15
p = 0.5
print(paste("P(45 < X < 54)=", sum(dbinom(46:54, n, p))))
print(paste("P(X <= 8) = ", pbinom(8, n, p, lower.tail=TRUE)))
print(paste("P(X > 8) = ", pbinom(8, n, p, lower.tail=FALSE)))

# Find x0 where P(X<=x0)=0.4
print(paste("x0 = ", qbinom(0.4, n, p, lower.tail=TRUE)))


###### GEOMETRIC DISTRIBUTION ######
### Consider X~geom(p=0.5)
p = 0.5
print(paste("P(X = 1) = ", dgeom(1, p)))
print(paste("P(X <= 1) = ", pgeom(1, p, lower.tail=TRUE)))
print(paste("P(X > 1) = ", pgeom(1, p, lower.tail=FALSE)))


###### POISSON DISTRIBUTION ######
### Consider Y~pois(lambda=4) ###
lambda = 4
print(paste("P(Y = 4) = ", dpois(4, lambda)))
print(paste("P(Y <= 10) = ", ppois(10, lambda, lower.tail=TRUE)))
print(paste("P(2 < Y < 10) = ", sum(dpois(3:9, lambda))))


###### NORMAL DISTRIBUTION ###### 
# (note: provided results use incorrect mean value. mu = 2 but are calculated with 3)
### Consider Y~N(mu=2, var=4) ###
mu = 2
var = 4
std = sqrt(var)
print(paste("P(Y <= 4) = F(4) = ", pnorm(4, mu, std)))
print(paste("P(Y <= 10) = F(10) = ", pnorm(10, mu, std)))
print(paste("P(2 < Y < 10) = F(10) - F(2) = ", pnorm(10, mu, std) - pnorm(2, mu, std)))


###### UNIFORM DISTRIBUTION ######
### Consider Y~unif(a=0, b=1) ###
a = 0
b = 1
print(paste("P(0.3 < Y < 0.5) = F(0.5) - F(0.3) = ", punif(0.5, a, b) - punif(0.3, a, b)))
print(paste("P(Y <= 1) = ", punif(1, a, b)))


###### EXPONENTIAL DISTRIBUTION ######
### Consider Y~exp(beta=0.8) ###
beta = 0.8
print(paste("P(Y > 5) = ", pexp(5, 1/beta, lower.tail=FALSE)))
print(paste("exp(-5/0.8) = ", exp(-5/beta)))


###### GAMMA DISTRIBUTION ######
### Consider Y~gamma(alpha=1.4, beta=2.3)
alpha = 1.4
beta = 2.3
print(paste("P(Y <= 10) = F(10) = ", pgamma(10, alpha, scale=beta)))
print(paste("P(2 < Y < 10) = F(10) - F(2) = ", pgamma(10, alpha, scale=beta) - pgamma(2, alpha, scale=beta)))
