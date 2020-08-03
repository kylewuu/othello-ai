#include "Reversi.h"

using namespace std;

Reversi::Reversi(void)
{

    main_loop();
};

void Reversi::print_intro()
{
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
         << "x                         x\n"
         << "x         Reversi         x\n"
         << "x                         x\n"
         << "xxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n " << endl;
}

void Reversi::init_boards()
{
    board = new int[64];
    legal_moves = new int[64];

    for (int i = 0; i < 64; i++)
    {
        board[i] = 0;
    }

    board[35] = 1;
    board[28] = 1;
    
    board[27] = 2;
    board[36] = 2;
}

void Reversi::clear_legal_moves()
{
    for(int i=0;i<64;i++)
    {
        legal_moves[i] = 0;
    }
}

void Reversi::print_boards()
{
    for (int i = 0; i < 8; i++)
    {

        // player board
        cout << " ";
        for (int j = 0; j < 8; j++)
        {

            cout << (board[(i * 8) + j] == 0 ? (legal_moves[(i * 8) + j] == 1 ? (((i * 8) + j > 9 ? " " : "  ") + std::to_string((i * 8) + j) + " ") : "    ") : (board[(i * 8) + j] == 1 ? " x  " : " O  ")) << ((j == 7) ? " " : " | ");
        }
        cout << "          ";

        // map board
        // for (int j = 0; j < 8; j++)
        // {

        //     cout << (legal_moves[(i * 8) + j] == 1 ? (((i * 8) + j > 9 ? " " : "  ") + std::to_string((i * 8) + j) + " ") : "    ") << ((j == 7) ? " " : " | ");
        // }

        // player board
        if (i != 7)
            cout << "\n-------------------------------------------------------";

        // map board
        // cout << "         ";
        // if (i != 7)
        //     cout << "-------------------------------------------------------";

        cout << "\n";
    }
    cout << "\n";
}

bool Reversi::is_int(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool Reversi::is_legal_move(string str)
{
    if (!is_int(str))
        return false;

    int int_input = stoi(str);

    for (int i = 0; i < 64; i++)
    {
        if (i == int_input && legal_moves[i] == 1)
        {

            return true;
        }
    }
    return false;
}

void Reversi::find_legal_moves()
{
    int opponent;
    int temp;
    bool piece_between;

    if(turn == 1) opponent = 2;
    else opponent = 1;

    for(int i=0;i<64;i++)
    {
        // cout << board[i];
        if(board[i] == turn)
        {
            // top left
            temp = i-9;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp+1)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp -= 9;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp+1)%8!=0 && piece_between) legal_moves[temp] = 1;

            // top
            temp = i-8;
            piece_between = false;
            while(temp < 64 && temp >= 0 && board[temp] == opponent)
            {
                piece_between = true;
                temp -= 8;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && piece_between) legal_moves[temp] = 1;

            // top right
            temp = i-7;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp -= 7;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp)%8!=0 && piece_between) legal_moves[temp] = 1;

            // right
            temp = i+1;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp += 1;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp)%8!=0 && piece_between) legal_moves[temp] = 1;

            // bottom right
            temp = i+9;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp += 9;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp)%8!=0 && piece_between) legal_moves[temp] = 1;

            // bottom
            temp = i+8;
            piece_between = false;
            while(temp < 64 && temp >= 0 && board[temp] == opponent)
            {
                piece_between = true;
                temp += 8;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && piece_between) legal_moves[temp] = 1;

            // bottom left
            temp = i+7;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp+1)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp += 7;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp+1)%8!=0 && piece_between) legal_moves[temp] = 1;

            // left
            temp = i-1;
            piece_between = false;
            while(temp < 64 && temp >= 0 && (temp+1)%8!=0 && board[temp] == opponent)
            {
                piece_between = true;
                temp -= 1;
            }
            if(temp < 64 && temp >= 0 && board[temp] == 0 && (temp+1)%8!=0 && piece_between) legal_moves[temp] = 1;
        }
        
    }
}

bool Reversi::check_for_end()
{
    for(int i=0;i<64;i++)
    {
        if(legal_moves[i] == 1) return false;
    }

    return true;
}

int Reversi::check_winner()
{
    int x = 0;
    int o = 1;

    for(int i=0;i<64;i++)
    {
        if(board[i] == 1) x += 1;
        else if(board[i] == 2) o += 1;
    }

    cout << "\nx: " << x;
    cout << "\nO: " << o;
    if(x > o) return 1;
    else if(o > x) return 2;
    return 0;
}

void Reversi::make_move(string str) // need to add the flipping 
{
    int int_input = stoi(str);

    

    int opponent;
    int temp;
    bool piece_between;

    if(turn == 1) opponent = 2;
    else opponent = 1;

    int i = int_input;

    // top left
    temp = i-9;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp -= 9;
    }
    if(board[temp] == turn && piece_between) 
    {

        temp = i-9;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp -= 9;
        }
    };

    // top
    temp = i-8;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp -= 8;

    }
    if(board[temp] == turn && piece_between) 
    {

        temp = i-8;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp -= 8;
        }
    };

    // top right
    temp = i-7;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp -= 7;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i-7;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp -= 7;
        }
    };

    // right
    temp = i+1;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp += 1;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i+1;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp += 1;
        }
    };

    // bottom right
    temp = i+9;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp += 9;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i+9;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp += 9;
        }
    };

    // bottom
    temp = i+8;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp += 8;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i+8;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp += 8;
        }
    };

    // bottom left
    temp = i+7;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp += 7;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i+7;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp += 7;
        }
    };

    // left
    temp = i-1;
    piece_between = false;
    while(temp < 64 && temp >= 0 && board[temp] == opponent)
    {
        piece_between = true;
        temp -= 1;
    }
    if(board[temp] == turn && piece_between) 
    {
        temp = i-1;
        while(temp < 64 && temp >= 0 && board[temp] == opponent)
        {
            board[temp] = turn;
            temp -= 1;
        }
    };

    board[int_input] = turn;
    if (turn == 1)
        turn = 2;
    else
        turn = 1;
    
}

void Reversi::read_input()
{
    bool is_int_flag = false;
    bool is_valid_space_flag = false;
    if (turn == 2) cout << "o (white): make a move: ";
    else if (turn == 1) cout << "x (black): make a move: ";
    cin >> input;
    is_valid_space_flag = is_legal_move(input);

    while (!is_valid_space_flag)
    {
        if (turn == 2) cout << "o (white): make a valid move: ";
        else if (turn == 1) cout << "x (black): make a valid move: ";
        cin >> input;
        is_valid_space_flag = is_legal_move(input);
    }
    cout << "\n";
    make_move(input);
}

void Reversi::main_loop()
{
    turn = 1;
    print_intro();
    init_boards();
    clear_legal_moves();
    find_legal_moves();
    print_boards();
    

    while (!check_for_end())
    {
        read_input();
        clear_legal_moves();
        find_legal_moves();
        print_boards();
    }

    cout << "Fini\n\n";
    int winner = check_winner();
    if(winner == 1) cout << "x is the winner";
    if(winner == 2) cout << "O is the winner";
    if(winner == 0) cout << "The match ended in a draw";
}