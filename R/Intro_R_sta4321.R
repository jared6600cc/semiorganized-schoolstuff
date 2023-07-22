#Introduction to R
#Library / package
install.packages("car")
library(datasets)
library(help = "car")

# Calculator 
x=10^2
y=2*x

# Vectors
vec1=c(1,21,50,80,45,0)
myquizzes= c(80,90,100,75,95)

myquizzes/100

datasets::airmiles
summary(myquizzes)

# Matrices
mymatrix=matrix(data = vec1,nrow = 4)


# Data frames

df1= data.frame(x=rnorm(100),y=rnorm(100,mean=5))

summary(df1)
x=df1$x
y=df1$y

# R Datasets
mdata=cars

# Math/Stat Functions 
sum(vec1)
mean(vec1)
sd(vec1)
min(vec1)
max(vec1)
abs(vec1)
sqrt(vec1)
2**9
2^9
exp(1)
log(1)
log10(10)
log2(2)
log(45,base = 45)
factorial(9)
choose(5,2)
summary(vec1)

# Example
ws=airquality$Wind
hist(ws,freq = FALSE)
lines(density(ws),col=2,lwd=2)
mean(ws)+1*sd(ws)
mean(ws)-1*sd(ws)


# Example Normal
x=rnorm(30)
hist(x,freq = FALSE)
lines(density(x),col=2,lwd=2)

t.test(rnorm(10),rnorm(10,mean=0))

# Probability Distibutions

#Binomial
#************************
# P(Y=3)
dbinom(x = 3, size = 100, prob = 0.05)
#P(X=46)
dbinom(46, 100, 0.5)
# Compute P(45 < X < 55) for X Binomial(100,0.5)
sum(dbinom(46:54, 100, 0.5))
# CDF 
pbinom(q = 50, 100, 0.5, lower.tail = T)
# ICDF 
qbinom(p = c(0.25,0.5,0.75), size = 100, prob = 0.5, lower.tail = T)
#P(Y<=y_0)=0.5

#Generate random numbers
rb=rbinom(n =500,size = 10,prob = 0.05)

# Histogram
hist(rb,freq = T)


#Geometric
#************************
datageo=rgeom(n = 10,prob = 0.5)

# Poisson
#************************
pdata=rpois(1000,20)
mean(pdata)
var(pdata)
dpois(x = 10,2)

hist(pdata)
hist(rnorm(3000))


# Normal Distribution
#************************
x=rnorm(100,mean=1,sd = 2)
pnorm(0,mean = 0,sd=1)
qnorm(0.5)



# Uniform
#************************
x=runif(10,min = 0,max = 1)
punif(8,min = 0,max = 100)

hist(runif(10000))

#Exponential
#************************
expdata=rexp(1000,rate = 1)
hist(expdata)
pexp(10,rate = 2)

dexp(10,rate = 1)

# Gamma
#************************
pgamma(q = 10,shape = 1,rate = 2)
hist(rgamma(1000,shape=3,rate=2))


# Examples Data Sets
library(help = "datasets")

mydata=airquality
hist(mydata$Wind,freq = F)
lines(density(mydata$Wind),col="red")

qqnorm(mydata$Wind)



data2011=read.table("data2011.txt")
data2011=read.table("data2011.txt")
data2011=read.table("data2011.txt")




model2011=lm(LoadY ~ Month + Week + Hour + T, data=data2011)
summary(model2011)


