var
	n,m,i,j,s,k:longint;
	a:array[1..30000]of longint;
	
	function lowbit(x:longint):longint;
	begin
		exit(x and(-x));
	end;
	
	function sum(x:longint):longint;
	begin
		sum:=0;
		while x>0 do begin
			sum:=sum+a[x];
			x:=x-lowbit(x);
		end;
	end;

	function sum(l,r:longint):longint;
	begin
		sum:=sum(r)-sum(l-1);
	end;
	
	procedure de(x:longint);
	begin
		while x<=n do begin
			dec(a[x]);
			x:=x+lowbit(x);
		end;
	end;
	
	function find(a,b,k:longint):longint;
		
		function dfind(l,r,k:longint):longint;
		var
			mid:longint;
		begin
			if l=r then exit(l);
			mid:=(l+r)div 2;
			if sum(a,mid)>=k then exit(dfind(l,mid,k)) else exit(dfind(mid+1,r,k));
		end;
	begin
		dfind(a,b,k);
	end;
	
begin
	readln(n,m);
	for i:=1 to n do a[i]:=lowbit(i);
	s:=n;
	for i:=n downto 1 do begin
		k:=(m-1) mod i+1;
		j:=sum(s mod n+1,n);
		if j>=k then begin
			s:=find(s mod n+1,n,k);
		end else begin
			s:=find(1,s-1,k-j);
		end;
		write(s,' ');
		de(s);
	end;
end.
