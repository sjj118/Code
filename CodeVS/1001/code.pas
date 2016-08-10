type
	NodeType=record
		rank,father:longint;
	end;
	SetType=array[0..501]of NodeType;
	Normal=record
		zi,mu:longint;
	end;
var
	r,n,m,i,j,k,s,t:longint;
	ans:normal;
	v:array[0..5001]of longint;
	x,y:array[0..5001]of longint;
	min:real;

	UFS:SetType;
	function gcd(a,b:longint):longint;
	begin
		if b=0 then exit(a);
		exit(gcd(b,a mod b));
	end;
	procedure jiyue(var a:Normal);
    var
        g:longint;
	begin
		g:=gcd(a.zi,a.mu);
		a.zi:=a.zi div g;
		a.mu:=a.mu div g;
	end;
    procedure output(a:normal);
    begin
		if a.mu=1 then write(a.zi) else write(a.zi,'/',a.mu);
    end;
	
	procedure make(root:longint);
	begin
		UFS[root].father:=root;
		UFS[root].rank:=1;
	end;

	procedure init;
	var
		i:longint;
	begin
		for i:=1 to 500 do make(i);
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
	
	procedure qsort;

    procedure sort(l,r: longint);
      var
         i,j,m,t: longint;
      begin
         i:=l;
         j:=r;
         m:=v[(l+r) div 2];
         repeat
           while v[i]<m do
            inc(i);
           while m<v[j] do
            dec(j);
           if not(i>j) then
             begin
                t:=v[i];
                v[i]:=v[j];
                v[j]:=t;
				t:=x[i];
                x[i]:=x[j];
                x[j]:=t;
				t:=y[i];
                y[i]:=y[j];
                y[j]:=t;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,m);
    end;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
begin
	readln(n,m);
	r:=0;
	for i:=1 to m do readln(x[i],y[i],v[i]);
	qsort;
	min:=maxlongint;
	readln(s,t);
	for i:=1 to m do begin
		if v[i]=v[i-1] then continue;
		init;
		for j:=i to m do begin
			if v[j]/v[i]>=min then break;
			union(x[j],y[j]);
			if judge(s,t) then begin
				min:=v[j]/v[i];
				ans.zi:=v[j];
				ans.mu:=v[i];
			end;
		end;
	end;
	if min=maxlongint then writeln('IMPOSSIBLE') else begin jiyue(ans); output(ans); end;
end.