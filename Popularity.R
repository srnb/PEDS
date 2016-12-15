#popularity Graph
 df<- read.table("popularity.txt", header = TRUE,sep =" " )
 chart_data<-melt(df,id='Popularity')
 names(chart_data)<- c('Popularity','func','value')
 ggplot() + geom_line(data = chart_data, aes(x = Popularity, y = value, color = func), size = .5)+scale_x_log10()+scale_y_log10()+xlab("Number of Objects")+ylab("Request Count")
