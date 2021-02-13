inFile <- read.csv(file.choose(),header=FALSE,sep=",") # file with info
outFile <- file.choose() # file to deposit summary
close(file(outFile, open="w")) # erasing all content in file
for (var in 1:(7*17)) {
    avg <- mean(inFile[,var])
    ci <- 1.96 * sd(inFile[,var]) / sqrt(nrow(inFile))
    cat(paste(avg,avg+ci,avg-ci,sep=","), file=outFile, append = TRUE, eol = "\n")
}