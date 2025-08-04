const mongoose = require('mongoose');
const express = require('express');
const app = express();

const port = 3000;

main().catch(err => console.log(err));


async function main() {
    //Change this for your actual database
    await mongoose.connect('mongodb://127.0.0.1:27017/library');

    //schema for a Book
    const BookSchema = new mongoose.Schema(
        {
            title: String,
            Book_ID: Number,
            author: String
        }
    )

    //Book model
    const Book = new mongoose.model('Book',BookSchema);

app.get('/search', async (req,res) => {
    const {type,value} = req.query;
    if (!type || !value){
        return res.status(400).send('Missing search type or value');
    }

    try{
    let results;
    //Searching branch
    if (type == 'title'){
        results = await Book.find({title: value});
    }
    else if (type == 'id'){
        results = await Book.find({Book_ID: Number(value)});
    }
    else if (type == 'author'){
        results = await Book.find({author: value});
    }    
    else{
        return res.status(400).send('Missing search type or value');
    }
    res.json(results);
    } catch(err){
    console.error(err);
    res.status(500).send('Database error');
    }

});


app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});

    /* Chunk of code that puts books into db
    //Book population of db 
    const Dune = new Book({title: 'Dune',Book_ID: 1,author:'Frank Herbert'});
    const JaneEyre = new Book({title: 'Jane Eyre', Book_ID: 2, author: 'Charlotte Bronte'});
    const ClockworkOrange = new Book({title: 'Clockwork Orange', Book_ID:3,author: 'Anthony Burgess'});
    const AnimalFarm = new Book({title: 'Animal Farm', Book_ID: 4, author: 'George Orwell'});


    await Dune.save();
    await JaneEyre.save();
    await ClockworkOrange.save();
    await AnimalFarm.save();
    console.log('Books saved!');

    //await Book.deleteMany({});
    */

}