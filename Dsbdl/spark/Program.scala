val input = "/home/jagdish/Desktop/spark/input.txt" // Input path here
val inputFile = sc.textFile(input)

// Split lines into words
val words = inputFile.flatMap(line => line.split("\\s+"))

// Create (word, 1) pairs
val wordPairs = words.map(word => (word, 1))

// Reduce by key (sum the counts)
val wordCounts = wordPairs.reduceByKey(_ + _)

val output = "/home/jagdish/Desktop/spark/output.txt" // Output path here
wordCounts.coalesce(1).saveAsTextFile(output)
