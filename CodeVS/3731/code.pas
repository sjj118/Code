var
	n,m,s,t,i,j,min:longint;
	g,r:array[0..10000]of array of longint;
	d:array[0..10000]of longint;
	l,done,can,b,now:array[0..10000]of boolean;

	function get(i:longint):boolean;
	var
		j:longint;
	begin
		for j:=1 to r[i,0] do begin
		    if not l[r[i,j]] then begin
		        l[r[i,j]]:=true;
		        get(r[i,j]);
		    end;
		end;
	end;
begin
	readln(n,m);
	for i:=1 to m do begin
		readln(s,t);
		inc(g[s,0]);
		g[s,g[s,0]]:=t;
		inc(r[t,0]);
		r[t,r[t,0]]:=s;
	end;
    readln(s,t);
	l[t]:=true;
	get(t);
	for i:=1 to n do begin
		can[i]:=true;
		for j:=1 to g[i,0] do begin
			if not l[g[i,j]] then can[i]:=false;
		end;
	end;
    for i:=1 to n do d[i]:=maxlongint div 2;
	d[s]:=0;
	fillchar(b,sizeof(b),false);
	for i:=1 to n do if not can[i] then b[i]:=true;
	for i:=1 to n do if can[i] then begin
		min:=1;
		while b[min] do inc(min);
		for j:=min+1 to n do if (not b[j])and(d[j]<d[min]) then min:=j;
		if (n=7000)and(d[min]=maxlongint div 2) then begin
		    for j:=1 to r[min,0] do if d[r[min,j]]<maxlongint div 2 then begin
		        writeln(min);
		    end;
		end;
		for j:=1 to g[min,0] do if not b[g[min,j]] then begin
			if d[min]+1<d[g[min,j]] then d[g[min,j]]:=d[min]+1;
		end;
		b[min]:=true;
	end;
	if d[t]=maxlongint div 2 then begin
	    writeln(-1);
	end else writeln(d[t]);
end.
