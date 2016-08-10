var
	n,k,i,j,test,a:longint;
	f:array[0..10000000]of longint;
	
	function find(x:longint):longint;
		function tfind(l,r:longint):longint;
		var	
			m:longint;
		begin
			if l=r then exit(l);
			m:=(l+r)div 2;
			if x<=f[m] then exit(tfind(m+1,r)) else exit(tfind(l,m));
		end;
	begin
		exit(tfind(1,k));
	end;
begin
	test:=0;
	readln(a);
	while a>=0 do begin
		inc(test);
		n:=1;
		f[0]:=maxlongint;
		k:=0;
		while a>=0 do begin
			if a<=f[k] then begin
				inc(k);
				f[k]:=a;
			end else begin
				j:=find(a);
				f[j]:=a;
			end;
			readln(a);
		end;
		writeln('Test #',test,':');
		writeln('  maximum possible interceptions: ',k);
		writeln;
		readln(a);
	end;
end.
