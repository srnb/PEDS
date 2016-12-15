#Histogram Plot
df<- read.table("ObjectSize.txt", header = TRUE,sep =" " )
ggplot(melt(df),aes(x=value))+geom_histogram()+facet_wrap(~variable)