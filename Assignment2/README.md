The solodity program represents a loaning system in the metacoin token.

Implemented the ```mulDiv``` and ```getCompoundInterest``` fucntions from the rescources given.
Modifier ```isOwner``` implemented to provide access of functions to owner only.


#Using the Program

Compile the code and deploy the loan contract from an owner account.
The following functions are implemented:
1. ```reqLoan```: Used to request loan at the adress of the sender from the owner
2. ```sendCoin```: Used to send MetaCoin from one account to another and emit the transfer.
3. ```settleDues```: Used to settle the dues by the owner. This can be accessed only by the owner.
4. ```getBalance```: Used to get the balance amount at an account address.
5. ```getCompoundInterest```: Used to calcuate the compound interest,
6. ```viewDues```: Used to view dues towards a certain creditor address. Can be accessed by the owner only.



