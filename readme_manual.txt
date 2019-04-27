Topic : Money management system - Group 101
Members : -Daryl Kevin (3035555248)
	      -Welvin Bun (3035557117)

Problem Statement : 
Nowadays, money has become a crucial aspect in our life. People constantly spend their money to do various transactions in fulfilling their needs. Hence, it is obvious that people want to manage and secure their money in the best way they can. This includes a good record system which allows data management to be efficient and handy. Traditionally, people used piece of papers and pen to record their monetary flows. This might not be the best way since paper is an easily-destructible material. It might also get lost or wet easily. Environmental concern also limits such conventional system which uses a lot of paper.
Therefore, we come with a solution called “Wealth management system 101”. This is a computer program that can be used to keep your monetary records more flexibly. It is super easy to use and provides a lot of useful features. 
Problem Settings :
Our system utilizes the advancement of technology in the making process. Your daily expenditure will be recorded and stored in a much more efficient manner. More specifically, your data will be stored in your computer in a form of .txt file. It is handy, editable, and doesn’t require any paper. It responds to current world's demand where everything comes in an instant. Especially for University Students, our management system would easily help them in monitoring their money while being far away from their parents. We assume that some common categories such as food and transportation will be the most important to be included.
Functionalities and features :
Add Record 
Print all records
Sort records chronologically
Search records
Edit existing records
Remove existing records
Show statistics of existing records
Settings
To make you understand more about our functions, we are presenting brief explanations of how these features work. 
1. Add Record
This functionality consists of 2 sub-functions. You can add record(s) in 2 ways. The first one is manual input and the other is file input. Manual input means you only can add one records at a time. For manual input, the program will ask you all the elements of the record one by one, and all you need to do is typing the details of your record. Furthermore, for file input, you have to type the filename to the program. It will read the input filename and get records from it. The format of the input file is as the following : 
DD/MM/YYYY incomeOrExpense Category Amount Note 
-incomeOrExpense :
1 for Income
2 for Expense
-Category (Income) :
1 for Salary
2 for Bank Loan
3 for Prize
4 for Gift
5 for Other (if you put this, you have to specify the category, example will be provided later)
-Category (Expense):
1 for Food
2 for Clothes
3 for Entertainment
4 for Transportation
5 for Other (if you put this, you have to specify the category, example will be provided later)
-Amount 
Enter the amount you wish to store in the program.

-Note (put “-” if there is no note)
For example : 
01/01/2019 1 1 10000 This month salary
The line above means 10000 Income from salary on January 1st 2019 with note “This month salary”

01/01/2019 2 5 Furniture 1000 New table from IKEA
The line above means 1000 Expense to buy a furniture on January 1st 2019 with note “New table from IKEA”

2.Print all records
This function allows you to print all your existing records to a file. Just specify the filename which you want your records to be printed on.

3.Sort all records chronologically
This function allows you to sort your records. If you add your records randomly, you can simply choose this option to sort them by date. But once you sort, you can’t change your records back to randomized order. Let’s say after you sort your records and you add additional records which make the order random again. You need to click this function once again to make your additional records match and with the sorted data chronologically.

4.Search Records
This function allows you to search existing records. The searching process can be done in 3 ways. Search by date, incomeOrExpense, and category. But note that these filters can’t be combined. You can only apply 1 filter at a time.

5.Edit existing records
This function allows you edit all existing records. Be careful to input the correct record, if the record you want to edit doesn’t exist, the program will not continue to next step. Once the record you want to edit is found, you also need to input all elements one by one from the beginning (No shortcut to only edit one element).

6.Remove existing records
This function is pretty clear. You can search specific record and delete it from your data. 

7.Show statistics
You can view the statistics of your monetary use. Statistics can be presented monthly or yearly. But you also need to make sure that there is at least one record that have month or year you want the statistics to be presented. Once the input is valid, the program will automatically create an output file which contain the statistics (Total records, total income, expense, percentage to food, transportation, etc)

8.Settings
This function allows you to change the current username or currency. If you change the currency, the amount of every record will be converted automatically to the updated currency by the program.

For example :
Assume you have this record :
01/01/2019 Expense Food HKD100 -
After you change the currency let’s say to USD, the record will be converted to
01/01/2019 Expense Food USD6.37 -

Input/Output specification : 
For input file, please kindly follow the instruction stated above (1.Add Record). The program doesn’t provide Screen output, because we consider that the records might be a lot, and this will not be effective. So, file output is used instead. We provide an example input file (It contains 10,000 records which are randomized using program).

Compilation and execution instruction :
-after cloning the repository from gitHub to your local computer. Please type “make program” to compile all source files into object codes and link these object codes into one executable named “program” (.exe)
-Next, simply type “program” to run the program, and feel free to play with the program.
-Finally, if you want to remove all the object codes and executable, simply type “make remove”

