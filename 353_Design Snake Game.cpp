class SnakeGame {
public:
    int w, h, pos;
    vector<pair<int, int>> food;
    vector<vector<bool>> hist;
    deque<pair<int, int>> q;

    SnakeGame( int width, int height, vector<pair<int, int>> food ) {
	    this->food = food;
	    w = width, h = height, pos = 0;
	    hist = vector<vector<bool>> ( h, vector<bool>( w, false ) );
	    hist[0][0] = true;
	    q.push_back( make_pair( 0, 0 ) );
    }

    int move( string direction ) {
    	int row = q.back().first, col = q.back().second;
    	pair<int, int> d = q.front(); q.pop_front();
    	hist[d.first][d.second] = false;

    	if ( direction == "U" ) row--;
    	else if ( direction == "D" ) row++;
    	else if ( direction == "L" ) col--;
    	else if ( direction == "R" ) col++;

	    if ( row < 0 || col < 0 || col >= w || row >= h || hist[row][col] )
	    	return -1;

	    hist[row][col] = true;;
	    q.push_back( make_pair( row, col ) );
	    if ( pos >= food.size() )
	    	return q.size() - 1;

	    if ( row == food[pos].first && col == food[pos].second ) {
	    	pos++;
	    	q.push_front( d );
	    	hist[d.first][d.second] = true;
    	}
	    return q.size() - 1;
    }
};