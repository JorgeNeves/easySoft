<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebApplication5._Default" %>

<asp:Content runat="server" ID="FeaturedContent" ContentPlaceHolderID="FeaturedContent">
    <section class="featured">
        <div class="content-wrapper">
            <hgroup class="title">
                <h1><%: Title %>.</h1>
                <h2>EasySoft -&nbsp; Social Network<br />
                    <br />
                    <br />
                <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" Height="0px" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged" Width="0px">
                    <asp:ListItem>Portuguese</asp:ListItem>
                    <asp:ListItem>English</asp:ListItem>
                </asp:RadioButtonList>
                </h2>
            </hgroup>
        </div>
    </section>
</asp:Content>
<asp:Content runat="server" ID="BodyContent" ContentPlaceHolderID="MainContent">
    <h3>Três passos para entrares na nossa rede social:</h3>
    <ol class="round">
        <li class="one">
            <h5>Regista-te na nossa Rede Social</h5>
            Ao registares-te no nosso site vais poder entrar na nossa comunidade, vais ter um perfil, amigos e muito mais.&nbsp;
            <asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click">Registar</asp:LinkButton>
        </li>
        <li class="two">
            <h5>Edita o ter perfil e faz amigos! Quantos mais amigos mais pontos!</h5>
            Podes editar o teu perfil. Podes colocar uma imagem a teu gosto, um estado de humor, etc&nbsp;
            <asp:LinkButton ID="LinkButton2" runat="server" OnClick="LinkButton2_Click">Perfil</asp:LinkButton>
        </li>
        <li class="three">
            <h5>Faz o download do jogo!</h5>
            Agora é so fazeres o download do jogo e divertir-te. Podes fazer o download do jogo neste link
            <asp:LinkButton ID="LinkButton3" runat="server" OnClick="LinkButton3_Click">Download</asp:LinkButton>
        </li>
    </ol>
</asp:Content>
