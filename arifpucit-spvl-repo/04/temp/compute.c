double mypower(double x, double y){
	double ans = 1;
	int i;
	for(i=0; i<y; i++)
		ans *= x; 
	return ans;
}
