
#CDF for any two days
df<- read.table("ObjectSize.txt", header = TRUE,sep =" " )
View(df)
 vals <- data.frame(r1=df$Day1,r2=df$Day2)
 View(vals)
 ecdfplot(~ r1 + r2, data=vals, auto.key=list(space='right'))
 vals <- data.frame(r1=df$Day1,r2=df$Day2)
 
#CDF plot for all seven days in single plot 
 vals <- data.frame(r1=df$Day1,r2=df$Day2,r3=df$Day3,r4=df$Day4,r5=df$Day5,r6=df$Day6,r7=df$Day7)
 ecdfplot(~ r1 + r2 + r3 + r4 + r5 + r6 + r7, data=vals, auto.key=list(space='right'))+xlab("Cumulative CDF") +ylab("X")


#CDF for all Seven Days different appraoach
df1 <- data.frame(
  x = c(df$Day1, df$Day2,df$Day3,df$Day4,df$Day5,df$Day6,df$Day7),g=gl(7,1999998)
 )
ggplot(df1, aes(x, colour = g)) + stat_ecdf()
ggplot(df1, aes(x, colour = g)) + stat_ecdf()+xlab("Cumulative Distribution")+ylab("Object Size")

#CDF Plot
 vals <- data.frame(r1=df$Day1,r2=df$Day2,r3=df$Day3,r4=df$Day4,r5=df$Day5,r6=df$Day6,r7=df$Day7)
ecdfplot(~ r1 + r2 + r3 + r4 + r5 + r6 + r7, data=vals, auto.key=list(space='right'))+xlab("Cumulative CDF") +ylab("X")