using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class User
    {
        [Key]
        private string UserID { get; set; }
        private string Nick { get; set; }
        private string Password { get; set; }
        private string Mail { get; set; }
        private string PrimeiroNome { get; set; }
        private string UltimoNome { get; set; }
        private DateTime DataDeNascimento { get; set; }
        private string Pais { get; set; }
        private string EstadoDeHumorID { get; set; }
        private string AvatarUrl { get; set; }
        private string PerfilFacebook { get; set; }
        private string PerfilLinkedIn { get; set; }
    }
}