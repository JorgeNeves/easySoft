<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Consult.aspx.cs" Inherits="WebApplication5.Profile.Consult" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="height: 265px">
    
        <asp:Label ID="Label1" runat="server" Text="Utilizador Registado"></asp:Label>
        <br />
        <asp:Button ID="Button7" runat="server" Text="Sugestões de Amigos" Width="288px" />
        <br />
        <asp:Button ID="Button8" runat="server" Text="Tamanho da Sua Rede Social" Width="288px" />
        <br />
        <asp:Button ID="Button3" runat="server" Text="Tag cloud das tags de todos os utilizadores" Width="288px" />
        <br />
        <asp:Button ID="Button4" runat="server" Text="Tag cloud das tags de todas as relações" Width="288px" />
        <br />
        <br />
        <asp:Label ID="Label2" runat="server" Text="Qualquer Utilizador"></asp:Label>
        <br />
        <asp:Button ID="btnusertag" runat="server" OnClick="Button1_Click" Text="Consultar suas Tags de utilizador" Width="295px" />
        <br />
        <asp:Button ID="btnusertagsrelacoes" runat="server" Text="Consultar suas Tags das relações" OnClick="btnusertagsrelacoes_Click" />
        <br />
        <asp:Button ID="Button5" runat="server" Text="Leader Board" Width="295px" />
        <br />
        <asp:Button ID="Button6" runat="server" Text="Dimensão da Rede" Width="294px" />
        <br />
    
    </div>
    <div style="height: 59px; width: 668px" id="tagcloud">
        <asp:Label ID="lbltipotag" runat="server"></asp:Label>
        <br />
        <asp:Label ID="lbltag" runat="server"></asp:Label>
    </div>
    </form>
    </body>
</html>
