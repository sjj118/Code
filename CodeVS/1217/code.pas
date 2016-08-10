var
	n,m,i,k:longint;
	r,d,s,t:array[1..1000000]of longint;
	mm,mark:array[1..5000000]of longint;
	
	function min(a,b:longint):longint;
	begin
		if a<b then exit(a) else exit(b);
	end;
	
	procedure buildtree;
	var
		i:longint;
	begin
		for i:=1 to n do begin
			mark[k+i]:=r[i];
			mm[k+i]:=r[i];
		end;
		for i:=k+n+1 to k*2+1 do mm[i]:=maxlongint div 3;
		for i:=k downto 1 do begin
			mm[i]:=min(mm[i*2],mm[i*2+1]);
		end;
	end;
	
	procedure change(l,r,d:longint);
	begin
		l:=l+k-1;
		r:=r+k+1;
		while (l xor r)<>1 do begin
			mm[l]:=min(mm[l*2],mm[l*2+1])+mark[l];
			mm[r]:=min(mm[r*2],mm[r*2+1])+mark[r];
			if (l and 1)=0 then begin
				mark[l+1]:=mark[l+1]+d;
				mm[l+1]:=mm[l+1]+d;
			end;
			if (r and 1)=1 then begin
				mark[r-1]:=mark[r-1]+d;
				mm[r-1]:=mm[r-1]+d;
			end;
			l:=l shr 1;
			r:=r shr 1;
		end;
	end;
	
	function query(l,r:longint):longint;
	begin
		l:=l+k-1;
		r:=r+k+1;
		query:=maxlongint;
		while (l xor r)<>1 do begin
			if (l and 1)=0 then query:=min(query,mm[l+1]);
			if (r and 1)=1 then query:=min(query,mm[r-1]);
			l:=l shr 1;
			r:=r shr 1;
		end;
		l:=l shr 1;
		while l>=1 do begin
			query:=query+mark[l];
		end;
	end;
begin
	readln(n,m);
	k:=1 shl (trunc(ln(n-1)/ln(2))+1)-1;
	for i:=1 to n do read(r[i]);
	buildtree;
	for i:=1 to m do readln(d[i],s[i],t[i]);
	for i:=1 to m do begin
		change(s[i],t[i],-d[i]);
		if query(1,n)<0 then begin
			writeln(-1);
			writeln(i);
			exit;
		end;
	end;
	writeln(0);
end.