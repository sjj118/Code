var
	n,m,i,cnt:longint;
	score,pa,size,head,son,next:array[0..305]of longint;
	f:array[0..305,0..305]of longint;
	done:array[0..305]of boolean;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
	
	function min(a,b:longint):longint;
	begin
		if a<b then exit(a) else exit(b);
	end;
	
	procedure addson(f,s:longint);
	begin
		inc(cnt);
		son[cnt]:=s;
		next[cnt]:=head[f];
		head[f]:=cnt;
	end;
	
	function dfs(k:longint):longint;
	var
		p:longint;
	begin
		p:=head[k];
		dfs:=1;
		while p>0 do begin
			dfs:=dfs+dfs(son[p]);
			p:=next[p];
		end;
		size[k]:=dfs;
	end;
	
	function solve(t,k:longint):longint;
	var
		p,i,j:longint;
	begin
		if done[t] then exit(f[t,k]);
		done[t]:=true;
		p:=head[t];
		while p>0 do begin
			for i:=size[t] downto 2 do begin
				for j:=1 to min(i-1,size[son[p]]) do begin
					f[t,i]:=max(f[t,i],f[t,i-j]+solve(son[p],j));
				end;
			end;
			p:=next[p];
		end;
		exit(f[t,k]);
	end;
begin
	readln(n,m);
	for i:=1 to n do readln(pa[i],score[i]);
	for i:=1 to n do addson(pa[i],i);
	dfs(0);
	for i:=1 to n do f[i,1]:=score[i];
	writeln(solve(0,m+1));
end.
