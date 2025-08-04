import fetch from 'node-fetch';

async function tests()
{
    const URL1 = 'http://localhost:3000/search?type=title&value=Dune';
    const URL2 = 'http://localhost:3000/search?type=id&value=2';
    const URL3 = 'http://localhost:3000/search?type=author&value=Anthony%20Burgess';
    const URL4 = 'http://localhost:3000/search?type=title&value=Animal%20Farm';

    //Test 1
    try {
      const res = await fetch(URL1);
      const data = await res.json();
      console.log('Test 1:',data);
    } catch (err) {
      console.error('Error on search 1',err);
    }
    //Test 2
        try {
      const res = await fetch(URL2);
      const data = await res.json();
      console.log('Test 2:',data);
    } catch (err) {
      console.error('Error on search 2',err);
    }
    //test 3
        try {
      const res = await fetch(URL3);
      const data = await res.json();
      console.log('Test 3:',data);
    } catch (err) {
      console.error('Error on search 3',err);
    }
    //Test 4
        try {
      const res = await fetch(URL4);
      const data = await res.json();
      console.log('Test 4:',data);
    } catch (err) {
      console.error('Error on search 4',err);
    }

}

tests();