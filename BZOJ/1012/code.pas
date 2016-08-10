var
	i:longint;
	m,d,n,t,tail,cnt:int64;
	a,queue:array[1..200000]of int64;
	c:char;
	
	function find(x:int64):int64;
	var
		l,r,m:int64;
	begin
		l:=1;
		r:=tail;
		while l<r do begin
			m:=(l+r)shr 1;
			if queue[m]<x then l:=m+1 else r:=m;
		end;
		exit(queue[l]);
	end;
begin
	readln(m,d);
	for i:=1 to m do begin
		readln(c,n);
		if c='A' then begin
			inc(cnt);
			a[cnt]:=(n+t)mod d;
			while (tail>0)and(a[cnt]>=a[queue[tail]]) do dec(tail);
			inc(tail);
			queue[tail]:=cnt;
		end else begin
			t:=a[find(cnt-n+1)];
			writeln(t);
		end;
	end;
end.
