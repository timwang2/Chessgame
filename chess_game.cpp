#include <iostream>
#include <typeinfo>
#include <cmath>

enum PIECE_TYPE{
	TYPE_PAWN = 0,
	TYPE_KNIGHT,
	TYPE_BISHOP,
	TYPE_ROOK,
	TYPE_QUEEN,
	TYPE_KING
};

enum COLOR{
	WHITE = 0,
	BLACK = 1
};
	
class pieces_linked
{ //linked list of all the pieces
	public:
		
		class piece
		{ //base class for all the piece types
			private:

				piece *next_piece; //pointer to next piece
				piece *prev_piece; // pointer to previous piece

			public:
				int x_position; //horizontal position of the piece
				int y_position;	//vertical pos of the piece
				int type;		//the way we can cast the base class ptr in the future
				int piece_color;
			
			virtual int checkValid(int, int,  piece*, pieces_linked *, pieces_linked *) = 0;
			virtual int checkCollision(int,int, pieces_linked*)=0;
			virtual ~piece(){}; // virtual destructor so we can get to destructing the children through a piece pointer
			friend class pieces_linked;
		};

		class pawn: public piece 
		{ //pawn class, contains a constructor and the definition of a virtual check valid function
			private:
			public:
				pawn(int x, int y, int color)
				{
					std::cout<< "pawn spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_PAWN;
					piece_color = color;
					std::cout<< x_position << ","<< y_position << "\n";
				}

				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";
						if(collision_Ptr -> piece_color == piece_color){
							std::cout<< "2\n";
							return 2;
						}
						else{
							std::cout<< "1\n";
							return 1;
						}

					} 	
					else{
						std::cout<< "no collision\n";
						return 0;
					}
				}

				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white)
				{
					if ((checkCollision(x_move, y_move, black)||checkCollision(x_move, y_move, white) == 1) && (((x_move == selected_piece-> x_position+1)||(x_move == selected_piece-> x_position-1)) && (y_move == (selected_piece->y_position + 1)))){
						std::cout<< "move is valid\n";
						selected_piece -> x_position = x_move;
						selected_piece -> y_position = y_move;
					}						
	
					else if(checkCollision(x_move, y_move,black) == 0 && (x_move == selected_piece-> x_position) && (y_move == (selected_piece->y_position + 1)))
					{
						std::cout<< "move is valid\n";
						selected_piece -> x_position = x_move;
						selected_piece -> y_position = y_move;
						return 1;
					}
					else{
						std::cout<<"move is not valid\n";
						return 0;
					}
				}
				~pawn(){ std::cout<< "deleting pawn\n";};


			friend class pieces_linked;
		};

		class knight: public piece 
		{		 //knight class, contains a constructor and the definition of a virtual check valid function
			private:
			public:
				knight(int x, int y, int color) 
				{
					std::cout<< "knight spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_KNIGHT;
					piece_color = color;
					std::cout<< piece::x_position << ","<< y_position << "\n";
				}

				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";
						if(collision_Ptr -> piece_color == piece_color){
							std::cout<< "2\n";
							return 2;
						}
						else{
							std::cout<< "1\n";
							return 1;
						}

					} 	
					else{
						std::cout<< "no collision\n";
						return 0;
					}
				}
	
				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white)
				{
				if((x_move == selected_piece-> x_position) && (y_move == (selected_piece->y_position + 1)))
					{
						std::cout<< "move is valid\n";
						selected_piece -> x_position = x_move;
						selected_piece -> y_position = y_move;
						return 1;
					}
					else{
						std::cout<<"move is not valid\n";
						return 0;
					}

				}

				~knight(){ std::cout<< "deleting knight\n";};
			friend class pieces_linked;
		};

		class bishop: public piece 
			{ 		//bishop class, contains a constructor and the definition of a virtual check valid function
			private:
			public:
				bishop(int x, int y,int color)
				{
					std::cout<< "bishop spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_BISHOP;
					piece_color = color;
					std::cout<< piece::x_position << ","<< y_position << "\n";
				}

				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";
						if(collision_Ptr -> piece_color == piece_color){
							std::cout<< "2\n";
							return 2;
						}
						else{
							std::cout<< "1\n";
							return 1;
						}

					} 	
					else{
						std::cout<< "no collision\n";
						return 0;
					}
				}

				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white)
				{
					if (x_move > x_position && y_move > y_position){
					
					}
					
					if (x_move < x_position && y_move < y_position){
					
					}
			
					if (x_move > x_position && y_move < y_position){

					}
		
					if (x_move< x_position && y_move > y_position{
					
					}
					
					else{
						std::cout<<"move is not valid\n";
						return 0;
					}

				}

				~bishop(){ std::cout<< "deleting bisop\n";};
			friend class pieces_linked;
		};

		class rook: public piece { 			//rook class, contains a constructor and the definition of a virtual check valid function
			private:
			public:
				rook(int x, int y, int color){
					std::cout<< "rook spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_ROOK;
					piece_color = color;
					std::cout<< piece::x_position << ","<< y_position << "\n";
				}
				
				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";

						std::cout<< "1\n";
						return 1;
					}
					std::cout<< "no collision\n";
					return 0;
				}

				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white){
					int fingerx;
					int fingery;	
					if (x_move == x_position && y_move == y_position){
						std::cout<< "move is not valid";
						return 0;
					}
					
					else if(x_move != x_position && y_move != y_position){
						std::cout<< "move is not valid";
						return 0;
					}
					
					else if(x_move != x_position || y_move != y_position){
						fingerx = x_position;
						fingery = y_position;
										
						while(x_move > x_position && y_move == y_position){
							if (checkCollision(x_position , y_move, black) || checkCollision(x_position, y_move, white)){
								std::cout<< "move is not valid";
								x_position = fingerx;
								return 0;
							}
							x_position++;
						}

						
						while(y_move > y_position && x_move == x_position){
							if (checkCollision(x_move , y_position ,black) || checkCollision(x_move, y_position, white)){
								std::cout<< "move is not valid";
								y_position = fingery;
								return 0;
							}
							y_position++;
						}

						
						while(x_move < x_position && y_move == y_position){
							if (checkCollision(x_move , x_position ,black) || checkCollision(x_move, x_position, white)){
								std::cout<< "move is not valid";
								x_position = fingerx;
								return 0;
							}
							x_position--;
						}

						
						while(y_move < y_position && x_move == x_position){

							if (checkCollision(x_move , y_position ,black) || checkCollision(x_move, y_position, white)){
								std::cout<< "move is not valid";
								y_position = fingery;
								return 0;
							}
							x_position--;
						}		
					}

					return 1;	
				}

				~rook(){ std::cout<< "deleting rook\n";};

			friend class pieces_linked;
		};

		class queen: public piece {			//queen class, contains a constructor and the definition of a virtual check valid function
			private:
			public:
				queen(int x, int y, int color){
					std::cout<< "queen spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_QUEEN;
					piece_color = color;
					std::cout<< piece::x_position << ","<< y_position << "\n";
				}

				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";
						if(collision_Ptr -> piece_color == piece_color){
							std::cout<< "2\n";
							return 2;
						}
						else{
							std::cout<< "1\n";
							return 1;
						}

					} 	
					else{
						std::cout<< "no collision\n";
						return 0;
					}
				}

				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white){
					if(((x_move- y_move) == ((selected_piece->x_position)-(selected_piece->y_position)))||(!(x_move == selected_piece-> x_position) != !(y_move == selected_piece->y_position))){
						std::cout<< "move is valid\n";
						selected_piece -> x_position = x_move;
						selected_piece -> y_position = y_move;
						return 1;
					}
					else{
						std::cout<<"move is not valid\n";
						return 0;
					}
				}

				~queen(){ std::cout<< "deleting queen\n";};

			friend class pieces_linked;
		};

		class king: public piece {			//king class, contains a constructor and the definition of a virtual check valid function
			private:
			public:

				king(int x, int y, int color){
					std::cout<< "king spawned\n";
					x_position = x;
					y_position = y;
					type = TYPE_KING;
					piece_color = color;
					std::cout<< piece::x_position << ","<< y_position << "\n";
				}

				int checkCollision(int x,int y, pieces_linked *color){
					piece *collision_Ptr;					
					if (color->pieces_linked::find(x,y)){
						collision_Ptr = color->search_Ptr;
						std::cout<< "collision happen\n";
						if(collision_Ptr -> piece_color == piece_color){
							std::cout<< "2\n";
							return 2;
						}
						else{
							std::cout<< "1\n";
							return 1;
						}

					} 	
					else{
						std::cout<< "no collision\n";
						return 0;
					}
				}

				int checkValid(int x_move, int y_move, piece *selected_piece, pieces_linked *black, pieces_linked *white){
					
					if(std::abs(x_move - (selected_piece-> x_position)) || std::abs(y_move - (selected_piece->y_position))){
						std::cout<< "move is valid\n";
						selected_piece -> x_position = x_move;
						selected_piece -> y_position = y_move;
						return 1;
					}
					else{
						std::cout<<"move is not valid\n";
						return 0;
					}
				}

				~king(){ std::cout<< "deleting king\n";};

			friend class pieces_linked;
		};

		piece *first_element;	//first element pointer
		piece *last_element;	//last element pointer
		piece *select_Ptr;		//pointer to search for elements
		piece *search_Ptr;
		piece *DESTRUCTION;	//destructor pointer
		
		pieces_linked(void){  //constructor for linked list
			first_element = NULL;
			std::cout<< "Linked List Initialized \n";
		};
		~pieces_linked(){ //DESTRUCTION no memory leaks pl0x
			std::cout<< "linked list destructed\n";
		};
	
	void board_setup(int);
	int find(int, int);
	int piece_search(int, int, pieces_linked*);
	void board_cleanup();		
	
	private:
};

void pieces_linked :: board_cleanup(){
	DESTRUCTION = first_element;
	while(DESTRUCTION != NULL){
		piece* next = DESTRUCTION->next_piece;
		delete DESTRUCTION;
		DESTRUCTION = next;
	}
}


void pieces_linked :: board_setup(int color){ //function to initialize the linked list for one color pieces, must do one for black and one for white
	piece *insert_piece;
	int row_variable;
	int row_variable_two;
	
	if(color == WHITE){
		row_variable = 2;
		row_variable_two = 1;
	}

	else if (color == BLACK){
		row_variable = 7;
		row_variable_two = 8;
	}

	insert_piece = new pawn(row_variable, 1, color);
	first_element = insert_piece;

		
	for (int i = 2; i<8; i++){
		insert_piece->next_piece = new pawn(row_variable,i, color);
		insert_piece->next_piece-> prev_piece = insert_piece;
		insert_piece =insert_piece->next_piece;
	}

	for (int i = 1; i<9; i +=7){
		insert_piece -> next_piece = new rook(row_variable_two,i, color);
		insert_piece->next_piece-> prev_piece = insert_piece;
		insert_piece =insert_piece->next_piece;
	}

	for (int i = 2; i<8; i+=5){
		insert_piece -> next_piece = new knight(row_variable_two,i, color);
		insert_piece->next_piece-> prev_piece = insert_piece;
		insert_piece =insert_piece->next_piece;
	}

	for (int i = 3; i<7; i+=3){
		insert_piece -> next_piece = new bishop(row_variable_two,i, color);
		insert_piece->next_piece-> prev_piece = insert_piece;
		insert_piece =insert_piece->next_piece;
	}
	
	insert_piece -> next_piece = new king(row_variable_two,5, color);
	insert_piece->next_piece-> prev_piece = insert_piece;
	insert_piece =insert_piece->next_piece;

	insert_piece -> next_piece = new queen(row_variable_two,4, color);
	insert_piece->next_piece-> prev_piece = insert_piece;
	insert_piece->next_piece->next_piece = NULL;

	last_element = insert_piece;
	

}
	
int pieces_linked::find(int x_input, int y_input){			//function to search for the piece that the user specifies
	piece *new_ptr;																		//goes through linked list searching for a position match to the square user specifies
	new_ptr = first_element;
	if((x_input > 8) || (x_input<1) || (y_input > 8) || (y_input<1)){
		std::cout<< "invalid input";
		return 0;
	}
	while ((new_ptr != NULL) && ((x_input != (new_ptr->x_position)) || (y_input != (new_ptr -> y_position)))){
		new_ptr = new_ptr->next_piece;
	}
	if (new_ptr == NULL) {
		std::cout<< "no such piece \n";
		return 0;
	} 
	else if((x_input == (new_ptr->x_position)) && (y_input == (new_ptr -> y_position))){
		search_Ptr = new_ptr;
		return 1;
	}
	
	else{
		std::cout<< "invalid input \n";
	}
}

int pieces_linked:: piece_search(int x_input, int y_input, pieces_linked* color){
	if (find(x_input, y_input)){
		select_Ptr = search_Ptr;
		switch(select_Ptr -> type){
			case TYPE_PAWN:
				std::cout<< "pawn selected \n";
				break;
			case TYPE_KNIGHT:
				std::cout<< "knight selected\n";
				break;
			case TYPE_BISHOP:
				std::cout<< "bishop selected\n";
				break;
			case TYPE_ROOK:
				std::cout<< "rook selected\n";
				break;
			case TYPE_QUEEN:
				std::cout<< "queen selected\n";	
			break;
			case TYPE_KING:
				std::cout<< "king selected\n";
				break;
		}
	return 1;
	}
	else{
		return 0;
	}
}

main(){
	std::cout<<"Hello, World";
	int player[2];
	int game = 1;

	pieces_linked *cursor = new pieces_linked;
	cursor->board_setup(BLACK);
	
	std::cin >> player[0]>>player[1];

	while(cursor->piece_search(player[0] ,player[1] , cursor) != 1){
		std::cin >> player[0]>>player[1];
	}
	std::cin >> player[0]>>player[1];
	cursor->select_Ptr->checkValid(player[0],player[1],cursor->select_Ptr, cursor, cursor);
	game = 0;	

	if(game = 0){
	cursor->board_cleanup();
	delete cursor;
	}
}

