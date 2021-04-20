%% ################################################################################
%%                  PAYOFF MATRIX GAME SIMULTOR
%% ################################################################################

%%------------------------------------

%%  Data
%%  -------------

% %%  For (1)  X = {{4, -3, 1, 3, 6, 2}, {5, 9, 3, 9, -5, 5}, {3, 8, 3, 5, 7, -7}, {-9, 9, 7, 3, 2, 4}, {9, 4, 8, -1, 1, 1}, {2, 4, -2, 2, 5, 9}};
% 
%   For (2) Y = {{1, 8, 8, 6, 3, 8}, {5, 5, 8, 9, 9, 9}, {3, 3, 3, 4, 8, 7}, {0, 2, 3, 3, 2, 5}, {7, 9, 4, 4, 6, 4}, {5, 0, 3, 5, 7, 1}};
% 
%   For (3)  Z = {{9, 8, 1}, {6, 7, 7}, {8, 8, 2}};
% 
% %%

% --------------------Working ---------------------------------------------
%   Part I and II
%   --------------
clc;

clear workspace

X = [4, -3, 1, 3, 6, 2; 5, 9, 3, 9, -5, 5; 3, 8, 3, 5, 7, -7; -9, 9, 7, 3, 2, 4; 9, 4, 8, -1, 1, 1; 2, 4, -2, 2, 5, 9]
Y = [1, 8, 8, 6, 3, 8; 5, 5, 8, 9, 9, 9; 3, 3, 3, 4, 8, 7; 0, 2, 3, 3, 2, 5; 7, 9, 4, 4, 6, 4; 5, 0, 3, 5, 7, 1]
% constant chosen for testing linear combination
const = 0.005

number_of_strategy_1 = 6;
number_of_strategy_2 = 6;
% game strategies based on matrix rows/columns
%Defining the number of possible strategies
[number_of_strategy_1, number_of_strategy_2] = size(X)
strategy_1 = 1: number_of_strategy_1
strategy_2 = 1: number_of_strategy_2
nonzero_strategy_1 = strategy_1;
nonzero_strategy_2 = strategy_2;
zero_strategy_1 = [];
zero_strategy_2 = [];
% game sttrategy properties fdn 

X_reduced = X;
Y_reduced = Y;
%produce reduced version of X
LK_1 = 1;
LK_2 = 1;

while LK_1~=0
    LK_1 = 0;
    pp = 1;
    
    while pp ~= 0
        pp = 0
        %defining area and parameters for which the program is to perform the cycle     
        %defining area and parameters for X
        for k=1:number_of_strategy_1-1
            for i=1:number_of_strategy_1
                %setting the conditions to validate the calculation             
                if 1~=k
                    if X_reduced(k,:) < X_reduced(1,:)
                       zero_strategy_1(end+1) =  nonzero_strategy_1(k)
                       nonzero_strategy_1(k) = []
                       X_reduced(k,:) = []
                       Y_reduced(:,k) = []
                       pp = pp+1;
                       number_of_strategy_1 = number_of_strategy_1 - 1;
                       disp(' Reduced rows from matrix X ');
                    end
                end
                if pp>0 break
                end
            end
        end

        %defining area and parameters for Y     
        for k=1:number_of_strategy_2-1
            for i=1:number_of_strategy_2
                %setting the conditions to validate the calculation             
                if 1~=k
                    if Y_reduced(k,:) < Y_reduced(1,:)
                       zero_strategy_2(end+1) =  nonzero_strategy_2(k)
                       nonzero_strategy_2(k) = []
                       Y_reduced(k,:) = []
                       X_reduced(:,k) = []
                       pp = pp+1;
                       number_of_strategy_2 = number_of_strategy_2 - 1;
                       disp(' Reduced rows from matrix Y ');
                    end
                end
                if pp>0 break
                end
            end
        end
    end
end


% Test of Linear Combination of Matrix X
disp(' Finding Linear Combination of Matrix X' )
% Using linprog to reduce the dominated strategies
for k=1:number_of_strategy_1-1
    matrix = X_reduced;
    a = -matrix(k,:)+const;
    matrix(k,:)=[];
    matrix = -matrix';
    lb = zeros(1, number_of_strategy_1-1);
    ub=lb+1;
    R = ones(1, number_of_strategy_1-1);
    r=1;
    c = zeros(1, number_of_strategy_1-1);
    [b,fval,exitflag,output,lambda]=linprog(c,matrix,a,R,r,lb,ub,[],[]); %for matlab
    %[b,fval,exitflag,output,lambda]=glpk(c,matrix,a,R,r,lb,ub,[],[]); %for GNU octave
    if exitflag>=0
        X_reduced=matrix'
        Y_reduced(:,k)=[]
        b
        zero_strategy_1(end+1)=nonzero_strategy_1(k)
        nonzero_strategy_1(k)=[]
        number_of_strategy_1=number_of_strategy_1-1;
        LK_1=LK_1+1
    end
    if number_of_strategy_1==2
        break
    end
end
%---------------Probability computation-----------------------
[r, c] = size(X);
y = zeros(r,c);
p = zeros(r,c);
for i = 1:c                               %Looping through the column.
    for j = 1:r                           %Looping through the row in that that column.
        y(j,i) = sum(A(:,[i]) == A(j,i)); %Compare each column of the matrix with the entries in that column.
        prob(j,i) = y(j,i)/r;                %Probability of each entry of a column within that column. 
    end
end
disp('Probability for options A, B, C')
prob
%------------------------------end-----------------------------


% Test of Linear Combination of Matrix Y
disp(' Finding Linear Combination of Matrix Y' )
% Using linprog to reduce the dominated strategies
for k=1:number_of_strategy_2-1
    matrix = Y_reduced;
    a = -matrix(k,:)+const;
    matrix(k,:)=[];
    matrix = -matrix';
    lb = zeros(1, number_of_strategy_2-1);
    ub=lb+1;
    R = ones(1, number_of_strategy_2-1);
    r=1;
    c = zeros(1, number_of_strategy_2-1);
     [b,fval,exitflag,output,lambda]=linprog(c,matrix,a,R,r,lb,ub,[],[]); %for matlab
     %[b,fval,exitflag,output,lambda]=glpk(c,matrix,a,R,r,lb,ub,[],[]); %for GNU octave
    if exitflag>=0
        X_reduced(:,k)=[]
        Y_reduced=-matrix'
        b
        zero_strategy_2(end+1)=nonzero_strategy_2(k)
        nonzero_strategy_2(k)=[]
        number_of_strategy_2=number_of_strategy_2-1;
        LK_2=LK_2+1
    end
    if number_of_strategy_2==2
        break
    end
end
%---------------Probability computation-----------------------
[r, c] = size(Y);
y = zeros(r,c);
p = zeros(r,c);
for i = 1:c                               %Looping through the column.
    for j = 1:r                           %Looping through the row in that that column.
        y(j,i) = sum(A(:,[i]) == A(j,i)); %Compare each column of the matrix with the entries in that column.
        prob(j,i) = y(j,i)/r;                %Probability of each entry of a column within that column. 
    end
end
disp('Probability for options A, B, C')
prob
%------------------------------end-----------------------------



%--------Game value calculation for matrices----------------
maxi = max(X); %find maximum in columns
maximin = min(maxi) %column wise minmax
x = transpose(X)  %transpose payoff matrix X
mini = min(x)
minimax = max(mini) %find maxmin in row wise

if(minimax == maximin)
  row = find(mini==minimax);
  col = find(maxi==maximin);
  
  disp('Saddle point exist')
  disp('Value of the game for Player 1 is: ')
  disp(row)
  disp('Value of the game for Player 2 is: ')
  disp(col)
  disp('Value of the game is: ')
  disp(minimax)
  disp('')
  disp('Game favors row player')
end
if(minimax != maximin)
  disp('')
  disp('Game favors column player')
end


%--------Game value calculation for matrices----------------
maxi = max(Y); %find maximum in columns
maximin = min(maxi) %column wise minmax
y = transpose(y)  %transpose payoff matrix X
mini = min(y)
minimax = max(mini) %find maxmin in row wise

if(minimax == maximin)
  row = find(mini==minimax);
  col = find(maxi==maximin);
  
  disp('Saddle point exist')
  disp('Value of the game for Player 1 is: ')
  disp(row)
  disp('Value of the game for Player 2 is: ')
  disp(col)
  disp('Value of the game is: ')
  disp(minimax)
  disp('')
  disp('Game favors row player')
end
if(minimax != maximin)
  disp('')
  disp('Game favors column player')
end



%   Part III
%   ---------

Z = [9, 8, 1; 6, 7, 7; 8, 8, 2];

%--------Game value calculation for matrices----------------
maxi = max(Z); %find maximum in columns
maximin = min(maxi) %column wise minmax
z = transpose(z)  %transpose payoff matrix X
mini = min(z)
minimax = max(mini) %find maxmin in row wise

if(minimax == maximin)
  row = find(mini==minimax);
  col = find(maxi==maximin);
  
  disp('Saddle point exist')
  disp('Value of the game for Player 1 is: ')
  disp(row)
  disp('Value of the game for Player 2 is: ')
  disp(col)
  disp('Value of the game is: ')
  disp(minimax)
  disp('')
  disp('Game favors row player')
end
if(minimax != maximin)
  disp('')
  disp('Game favors column player')
end
  
