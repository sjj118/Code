type
	NodeType=record
		rank,father:longint;
	end;
	SetType=array[1..50000]of NodeType;
var
	UFS:SetType;
	n,k,d,x,y,ans,i,t,tt:longint;
	eat,food:array[0..50000]of longint;
	
	procedure make(root:longint);
	begin
		UFS[root].father:=root;
		UFS[root].rank:=1;
	end;
	
	procedure init;
	var
		i:longint;
	begin
		for i:=1 to 50000 do make(i);
	end;
	
	function find(p:longint):longint;
	begin
		if UFS[p].father=p then exit(p);
		UFS[p].father:=find(UFS[p].father);
		exit(UFS[p].father);
	end;

	procedure union(a,b:longint);
	var
		x:longint;
	begin
		a:=find(a);
		b:=find(b);
		if UFS[a].rank<UFS[b].rank then begin
			inc(UFS[b].rank);
			UFS[a].father:=b;
		end else begin
			inc(UFS[a].rank);
			UFS[b].father:=a;
		end;
	end;
	
	function judge(a,b:longint):boolean;
	begin
		exit(find(a)=find(b));
	end;

begin
	init;
	readln(n,k);
	ans:=0;
	for i:=1 to k do begin
		readln(d,x,y);
		if (x>n)or(y>n)or((x=y)and(d=2)) then begin inc(ans); continue; end;
		if x=y then continue;
		if d=1 then begin
			if (eat[find(x)]=find(y))or(eat[find(y)]=find(x)) then inc(ans) else begin 
				if eat[find(x)]>0 then t:=eat[find(x)];
				if eat[find(y)]>0 then t:=eat[find(y)];
				if food[find(x)]>0 then tt:=food[find(x)];
				if food[find(y)]>0 then tt:=food[find(y)];
				union(x,y);
				eat[find(x)]:=t;
				food[t]:=find(x);
				eat[tt]:=find(x);
				food[find(x)]:=tt;
			end;
		end else begin
			if (judge(x,y))or(eat[find(y)]=x) then inc(ans) else begin
				if eat[find(x)]<>0 then union(find(y),eat[find(x)]);
				if food[food[find(x)]]<>0 then union(food[food[find(x)]],find(y));
				if eat[eat[find(y)]]<>0 then union(eat[eat[find(y)]],find(x));
				eat[find(x)]:=find(y);
				food[find(y)]:=find(x);
			end;
		end;
	end;
	writeln(ans);
end.
