A. To request data from my microservice you should connect to the same port and make sure the mongodb information is entered correctly for your database. Once you have done this,
you will need to call it using http. The format I have used is 'http://localhost:3000/search?type=TYPE&value=VALUE', where type is either id,author or title(enter in all lowercase).
If you aren't connecting to localhost port 3000 that will look different, an example call that I used was: 'http://localhost:3000/search?type=title&value=Dune' which will set the
type to title and the title value as Dune which gets passed into my microservice and searched the mongoose database.
B. To receive data from my microservice, you should monitor the same port you connected to receive and once my microservice has found the correct book, it will return it over
the same port for the main program to do with it as needed. It works the same as the request for data, in the code however I did await.res.json() to receive the data in the program
and it returns it as a JSON.

