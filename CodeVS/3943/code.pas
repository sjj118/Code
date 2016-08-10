var
	k,i,p,q,l,r,n,a:longint;
	x:int64;
	ans:array[1..82]of longint;
	
	function mi(a,k:longint):int64;
	var
		i:longint;
	begin
		mi:=1;
		for i:=1 to k do mi:=mi*a;
	end;
	
	function count(a:longint):int64;
	begin
		exit(p*mi(a,k)+q);
	end;
	
	function cou(x:longint):longint;
	begin
		cou:=0;
		while x>0 do begin
			cou:=cou+x mod 10;
			x:=x div 10;
		end;
	end;
	
begin
	readln(k,p,q,l,r);
	n:=0;
	for a:=0 to 81 do begin
		x:=count(a);
		if x>r then break;
		if (x>=l) and (cou(x)=a) then begin
			inc(n);
			ans[n]:=x;
		end;
	end;
	writeln(n);
	for i:=1 to n do write(ans[i],' ');
end.
