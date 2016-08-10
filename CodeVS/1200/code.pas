var
	x,y:array[1..10000000]of longint;
	a,b,h,i:longint;
	
	procedure gcd(a,b:longint);
	begin
		if b=0 then exit;
		inc(h);
		x[h]:=a div b;
		gcd(b,a mod b);
	end;
begin
    readln(a,b);
	h:=1;
	gcd(a,b);
	dec(h);
	y[1]:=1;
	y[2]:=x[h];
	for i:=3 to h+1 do begin
		y[i]:=x[h-i+2]*y[i-1]+y[i-2];
	end;
	if h mod 2=0 then writeln(y[h+1]) else writeln(b-y[h+1]);
end.
