using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;
using System.Globalization;
using System.Web.Security;
namespace MvcApplication1.Models
{
    [Table("UserProfile")]
    public class UserProfile
    {
        [Key]
        [DatabaseGeneratedAttribute(DatabaseGeneratedOption.Identity)]
        public int UserId { get; set; }
        public string UserName { get; set; }

        public string Mail { get; set; }
        public string PrimeiroNome { get; set; }
        public string UltimoNome { get; set; }
        public DateTime DataDeNascimento { get; set; }
        public string Pais { get; set; }
        public int EstadoDeHumorID { get; set; }
        public string AvatarUrl { get; set; }
        public string PerfilFacebook { get; set; }
        public string PerfilLinkedIn { get; set; }
    }
}