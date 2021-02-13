inFile <- read.csv(file.choose(),header=FALSE,sep=",") # file with info
outFile <- file.choose() # file to deposit summary
close(file(outFile, open="w")) # erasing all content in file
mon <- 0
tue <- 0
wed <- 0
thu <- 0
fri <- 0
sat <- 0
sun <- 0
for (var in 1:17) {
    mon <- mon + mean(inFile[,(var*7-6)])
    tue <- tue + mean(inFile[,(var*7-5)])
    wed <- wed + mean(inFile[,(var*7-4)])
    thu <- thu + mean(inFile[,(var*7-3)])
    fri <- fri + mean(inFile[,(var*7-2)])
    sat <- sat + mean(inFile[,(var*7-1)])
    sun <- sun + mean(inFile[,(var*7-0)])
}
cat(paste(mon/17,tue/17,wed/17,thu/17,fri/17,sat/17,sun/17,sep=","), file=outFile, append = TRUE, eol = "\n")