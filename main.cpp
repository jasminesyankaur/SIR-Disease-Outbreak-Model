#include<iostream>

using namespace std;

	const int SIZE = 7;

	void initialize(char current[SIZE][SIZE], int next[SIZE][SIZE]);
	void infect(char current[SIZE][SIZE], int next[SIZE][SIZE]);
	void recover(char current[SIZE][SIZE], int next[SIZE][SIZE]);
	void replace (char current[SIZE][SIZE], int next [SIZE][SIZE]);
	void print(char current[SIZE][SIZE]);
	int count(char current[SIZE][SIZE]);

int main ()
{
	 cout << "+-----------------------------------------------------+|" << endl;
         cout << "|      Computer Science and Engineering                |" << endl;
         cout << "|        CSCE 1030 - Computer Science I                |" << endl;                    //name , email, euid, class and dept.
         cout << "|  Jasmine Kaur     jk0573    jasminekaur@my.unt.edu   |" << endl;
         cout << "|+----------------------------------------------------+|" << endl;


	int day = 0;											//int to store day number 
	int x, y;											//int to store users coordinates 
	bool check = true;										//bool to enter the while loop
	int numOfi;											//int to store number of i in the grid
	char current[SIZE][SIZE];									//array to represent current day's region
	int next[SIZE][SIZE];										//array to represent next day's region 

	cout << "Please enter a location to infect: ";
	cin >> x >> y;											//asking user fot coordinates and storing in x and y

	while (check != false) 										//while the bool is true the program will enter the loop
	{
		if (x > SIZE || y > SIZE || x < 0 || y < 0) 						//checking if the user entered coordinates are vaild
		{
			cout << "Those coordinates are outside the bounds of this region." << endl;
			cout << "Please enter a new location to infect: ";
	                cin >> x >> y;									
		}
		else 
		{
			break;										//if false will exit loop
		}
	}

	initialize(current, next);									//using intialize function to set all positions to s

	current[x-1][y-1] = 'i';									//setting position to i

	
	cout << "Day " << day << endl;									//displaying day
	print(current);											//using print function to display current region

	while (numOfi != 0) 										//loop will execute while there are still 'i's in the grid
	{
		day++;											//updating day
		cout << "Day " << day << endl;								//displaying day
		infect(current, next);									//infecting region
		recover(current, next);									//recovering region 
		replace(current, next);									//replacing current with next day's array
		print(current);										//printing new array
		numOfi = count(current);								//keeping count of # of i 
		
	}	
	
	cout << "It took " << day+1 << " days for the outbreak to end." << endl;			//displaying how many days it took for the outbreak to end 

	return 0;
}

	void initialize(char current[SIZE][SIZE], int next[SIZE][SIZE])					
	{	
		for (int i = 0; i < SIZE; i++) 
		{
			for (int j = 0; j < SIZE; j++) 
			{
				current[i][j] = 's';							//intializing current and next day's array with 's'
				next[i][j] = 's';
			}	
		}
	}


	void infect(char current[SIZE][SIZE], int next[SIZE][SIZE])
	{
		for (int i = 0; i < SIZE; i++) 
		{
                	for (int j = 0; j < SIZE; j++) 
			{
                        	if (current[i][j] == 'i') 						//if the current position equals i then will check the following if statements 

	/*The following if statements will check every position arouund the user entered coordinate and if it finds an 's' it will update the next days array at the position with an 'i' to infect the region */
				{
					if (i-1 >= 0 && i-1 < SIZE &&  j-1 >=0 && j-1 < SIZE) 		
				{	
							if(current[i-1][j-1] == 's')
							{
								next[i-1][j-1] = 'i';
							}
				}	

				if (i -1 >= 0 && i -1 < SIZE && j >= 0 && j < SIZE)
				{
					if(current[i-1][j] == 's')
					{	
						next[i-1][j] = 'i';
					}	
				}

		
				if (i-1 >= 0 && i-1 < SIZE && j+1 >= 0 && j+1 < SIZE)
				{
					if(current[i-1][j+1] == 's')
					{
						next[i-1][j+1] = 'i';
					}
				}
						
				if (i >= 0 && i < SIZE && j+1 >= 0 && j+1 < SIZE)
				{
					if(current[i][j+1] == 's')
					{
						next[i][j+1] = 'i';
					}
					
				}

				if(i+1 >= 0 && i+1 < SIZE && j+1 >=0 && j+1 < SIZE)
				{
					if(current[i+1][j+1] == 's')
					{
						next[i+1][j+1] = 'i';
					}
				}

				if(i+1 >= 0 && i+1 < SIZE && j >= 0 && j < SIZE)
				{
					if(current[i+1][j]== 's')							
					{
						next[i+1][j] = 'i';
					}
				}
				
				if(i+1 >=0 && i+1 < SIZE && j-1 >= 0 && j-1 < SIZE)
				{
					if(current[i+1][j-1] == 's')
					{
						next[i+1][j-1] = 'i';
					}
				}
				if(i >= 0 && i < SIZE && j-1 >= 0 && j-1 < SIZE)
				{
					if(current[i][j-1] == 's')
					{
						next[i][j-1] = 'i';							

					}
				}
			}
		}
	}
}

	void recover(char current[SIZE][SIZE], int next[SIZE][SIZE]) 
	{
		for (int i = 0; i < SIZE; i++) 
		{
        	        for (int j = 0; j < SIZE; j++) 
			{
				if (current[i][j] == 'i') 						//if the current position is an i it will update the next days array with an 'r' 
				{
					next[i][j] = 'r';
				}
				
			}
		}
	}	
	
	void replace(char current[SIZE][SIZE], int next[SIZE][SIZE])					//this function will update the current array with the next day's array to update the spread of the infection 
	{
 		for (int i = 0; i < SIZE; i++) 
		{
                	for (int j = 0; j < SIZE; j++) 
			{
				current[i][j] = next[i][j];
			}		
		}	
	}	


	void print(char current[SIZE][SIZE]) 								//this funtion will print out the arrays
	{
        	for (int i = 0; i < SIZE; i++) 
		{
                	for (int j = 0; j < SIZE; j++) 
			{
				cout << current[i][j] << " ";      
                	}
				cout << endl;
        	}	
	}	

	int count(char current[SIZE][SIZE]) 								//this function keeps count of the number of i in the function and returns the value 
	{
		int count = 0;
			for (int i = 0; i < SIZE; i++) 
			{
                		for (int j = 0; j < SIZE; j++) 
				{
                     		   if (current[i][j] == 'i') 
					{
						count++;		
					}	
                		}
        		}
	return count;
	}	
